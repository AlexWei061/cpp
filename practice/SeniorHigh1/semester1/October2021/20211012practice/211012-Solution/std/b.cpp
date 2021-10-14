#include <bits/stdc++.h>

using namespace std;

const long long INF = 1ll << 60;

int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> part(5);
  int n = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> part[i];
    n += part[i];
  }
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    g[l].emplace_back(r, r - l);
    g[r].emplace_back(l, r - l);
  }
  auto dijkstra = [&](int s) {
    priority_queue<pair<long long, int>> que;
    vector<long long> dist(n + 1, INF);
    vector<bool> used(n + 1);
    dist[s] = 0;
    que.emplace(-dist[s], s);
    while (!que.empty()) {
      int v = que.top().second;
      que.pop();
      if (used[v]) {
        continue;
      }
      used[v] = true;
      for (auto e : g[v]) {
        int u = e.first, w = e.second;
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          que.emplace(-dist[u], u);
        }
      }
    }
    return dist;
  };
  int a = part[0], b = a + part[1], c = b + part[2], d = c + part[3];
  vector<long long> foo = dijkstra(a);
  vector<long long> bar = dijkstra(b);
  vector<long long> baz = dijkstra(c);
  long long ans = min(foo[b] + baz[d], min(foo[c] + bar[d], foo[d] + bar[c]));
  if (ans >= INF) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}
