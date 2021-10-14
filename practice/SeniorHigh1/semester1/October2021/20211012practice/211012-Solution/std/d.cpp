#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = 1;
  while (m < n) {
    m <<= 1;
  }
  vector<int> b(m);
  function<void(int, int, int)> dfs = [&](int v, int p, int d) {
    if (d) {
      b[m - d - 1] ^= a[v];
    }
    for (int u : g[v]) {
      if (u != p) {
        dfs(u, v, d + 1);
      }
    }
  };
  dfs(0, -1, 0);
  for (int i = 1; i < m; i <<= 1) {
    for (int j = 0; j < m; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        b[j + k] ^= b[j + k + i];
      }
    }
  }
  while (q--) {
    int t;
    cin >> t;
    cout << ((t ? b[(t - 1) % m] : 0) ^ a[0]) << "\n";
  }
  return 0;
}
