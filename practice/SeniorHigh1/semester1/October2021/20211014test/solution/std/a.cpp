#include <bits/stdc++.h>

using namespace std;

struct edge {
  int from, to, cost, id;

  bool operator<(const edge& o) const {
    return cost > o.cost;
  }
};

struct dsu {
  vector<int> p;

  dsu(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int v) {
    while (v != p[v]) {
      v = p[v] = p[p[v]];
    }
    return v;
  }

  void unite(int v, int u) {
    p[find(v)] = find(u);
  }
};

int main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<edge> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i].from >> e[i].to >> e[i].cost;
    --e[i].from; --e[i].to;
    e[i].id = i;
  }
  sort(e.begin(), e.end());
  vector<dsu> d(k, n);
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int l = 0, r = k;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (d[mid].find(e[i].from) == d[mid].find(e[i].to)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    if (r < k) {
      ans[e[i].id] = r + 1;
      d[r].unite(e[i].from, e[i].to);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
