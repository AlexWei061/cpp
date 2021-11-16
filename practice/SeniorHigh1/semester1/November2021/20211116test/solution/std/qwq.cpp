#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000005, mod = 998244353;

int n, f[N], ans[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1) tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}

int main() {
  freopen("qwq.in", "r", stdin);
  freopen("qwq.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> f[i];

  int iv = power(n - 1, mod - 2);
  for (int i = 1, s = 0; i <= n; i++)
    f[i] = (f[i] + 1ll * s * iv) % mod, s = add(s, f[i]);

  for (int i = n, s = 0; i; i--)
    ans[i] = 1ll * s * iv % mod, s = add(s, f[i]);

  for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}