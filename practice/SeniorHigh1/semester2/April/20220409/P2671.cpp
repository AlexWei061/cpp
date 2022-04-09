#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MOD 10007
#define MAXN 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int x[MAXN] = { 0 };
int c[MAXN] = { 0 };
int s[MAXN][2] = { 0 };
int sum[MAXN][2] = { 0 };

signed main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= n; i++) x[i] = in % MOD;
	for(int i = 1; i <= n; i++){
		c[i] = in; s[c[i]][i % 2]++;
		sum[c[i]][i % 2] = (sum[c[i]][i % 2] + x[i]) % MOD;
	}
	for(int i = 1; i <= n; i++)
		ans = (ans + i % MOD * (sum[c[i]][i % 2] + (s[c[i]][i % 2] - 2) % MOD * x[i]) % MOD) % MOD;
	cout << ans << '\n';
	return 0;
}