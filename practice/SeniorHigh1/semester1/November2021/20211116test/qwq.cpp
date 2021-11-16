#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000
#define MOD 998244353

int n = 0;
int f[MAXN] = { 0 };
int ans[MAXN] = { 0 };

inline int add(int x, int y){
	return x + y < MOD ? x + y : x + y - MOD;
}

int qp(int a, int n) {
	int ans = 1 % MOD;
	for(; b; b >>= 1){
		if(b & 1) ans = 1ll * ans * a % MOD;
		a = 1ll * a * a % MOD;
	}
	return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
  int iv = qp(n - 1, MOD - 2);
  for (int i = 1, s = 0; i <= n; i++)
    f[i] = (f[i] + 1ll * s * iv) % MOD, s = add(s, f[i]);
  for (int i = n, s = 0; i; i--)
    ans[i] = 1ll * s * iv % MOD, s = add(s, f[i]);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  puts("");
}