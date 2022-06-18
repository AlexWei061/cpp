#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int s[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

int main(){
	n = in; memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) f[i][i] = 0, s[i] = s[i - 1] + a[i];
	for(int len = 2; len <= n; len++)
		for(int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			for(int k = l; k < r; k++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			f[l][r] += s[r] - s[l - 1];
		}
	cout << f[1][n] << '\n';
	return 0;
}