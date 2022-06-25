#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define MOD 19650827

int n = 0;
int a[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };
int g[MAXN][MAXN] = { 0 };

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) f[i][i] = 1;
	for(int len = 1; len <= n; len++)
		for(int l = 1; l + len <= n; l++){
			int r = l + len;
			f[l][r] = ((f[l + 1][r] * (a[l] < a[l + 1])) + g[l + 1][r] * (a[l] < a[r])) % MOD;
			g[l][r] = ((f[l][r - 1] * (a[r] > a[l])) + g[l][r - 1] * (a[r] > a[r - 1])) % MOD;
		}
	cout << (f[1][n] + g[1][n]) % MOD << '\n';
	return 0;
}