#include <bits/stdc++.h>

using namespace std;

const int INF = 0x1f3f3f3f;

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  if (k >= n || k > m) {
    cout << -1 << "\n";
    return 0;
  }
  vector<vector<pair<int, int>>> g(n + 5 - k);
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v; --u;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }
  for (int i = 0; i < 5 - k; ++i) {
    g[n + i - 1].emplace_back(n + i, 0);
    g[n + i].emplace_back(n + i - 1, 0);
  }
  n += 5 - k;
  auto init = [&](int v) {
    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(3, make_pair(INF, -1)));
    for (auto e1 : g[v]) {
      int u1 = e1.first, w1 = e1.second;
      if (u1 == 0 || u1 == n - 1) {
        continue;
      }
      for (auto e2 : g[u1]) {
        int u2 = e2.first, w2 = e2.second;
        if (u2 == 0 || u2 == n - 1) {
          continue;
        }
        pair<int, int> r(w1 + w2, u1);
        if (r < dist[u2][0]) {
          dist[u2][2] = dist[u2][1];
          dist[u2][1] = dist[u2][0];
          dist[u2][0] = r;
        } else if (r < dist[u2][1]) {
          dist[u2][2] = dist[u2][1];
          dist[u2][1] = r;
        } else if (r < dist[u2][2]) {
          dist[u2][2] = r;
        }
      }
    }
    return dist;
  };
  vector<vector<pair<int, int>>> foo = init(0);
  vector<vector<pair<int, int>>> bar = init(n - 1);
  int ans = INF;
  for (int v = 1; v < n - 1; ++v) {
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      if (u == 0 || u == n - 1) {
        continue;
      }
      int pv = 0, pu = 0;
      if (foo[v][pv].second == u) {
        ++pv;
      }
      if (bar[u][pu].second == v) {
        ++pu;
      }
      if (foo[v][pv].second != bar[u][pu].second) {
        ans = min(ans, foo[v][pv].first + bar[u][pu].first + w);
      } else {
        int qv = pv + 1, qu = pu + 1;
        if (foo[v][qv].second == u) {
          ++qv;
        }
        if (bar[u][qu].second == v) {
          ++qu;
        }
        ans = min(ans, foo[v][pv].first + bar[u][qu].first + w);
        ans = min(ans, foo[v][qv].first + bar[u][pu].first + w);
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << "\n";
  return 0;
}
