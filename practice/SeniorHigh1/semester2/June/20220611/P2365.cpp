#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 5050

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int t[MAXN] = { 0 };
int c[MAXN] = { 0 };
int T[MAXN] = { 0 };
int C[MAXN] = { 0 };
int f[MAXN] = { 0 };
int n = 0; int s = 0;

signed main(){
	n = in; s = in;
	for(int i = 1; i <= n; i++) t[i] = in, c[i] = in;
	for(int i = 1; i <= n; i++) T[i] = T[i - 1] + t[i], C[i] = C[i - 1] + c[i];
	memset(f, 0x3f, sizeof(f)); f[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			f[i] = min(f[i], f[j] + T[i] * (C[i] - C[j]) + s * (C[n] - C[j]));
	cout << f[n] << '\n';
	return 0;
}