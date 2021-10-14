#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int power(int x, int y) {
  int r = 1;
  while (y) {
    if (y & 1) {
      r = (long long) r * x % P;
    }
    x = (long long) x * x % P;
    y >>= 1;
  }
  return r;
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  auto solve = [&](int e) {
    vector<int> dp(e * m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m * 2; ++i) {
      for (int j = 1; j <= e * m; ++j) {
        dp[j] = (dp[j] + dp[j - 1]) % P;
      }
      for (int j = e * m; j > e; --j) {
        dp[j] = (dp[j] + P - dp[j - e - 1]) % P;
      }
    }
    return dp[e * m];
  };
  int same = 1;
  int ways = 1;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) {
        n /= p;
        ++e;
      }
      same = (long long) same * solve(e) % P;
      ways *= e + 1;
    }
  }
  if (n != 1) {
    same = (long long) same * solve(1) % P;
    ways *= 2;
  }
  cout << (long long) (same + power(ways, m * 2)) * (P + 1) / 2 % P << "\n";
  return 0;
}
