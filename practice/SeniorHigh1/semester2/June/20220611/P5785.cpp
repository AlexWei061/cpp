#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 300300

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int t[MAXN] = { 0 };
int c[MAXN] = { 0 };
int T[MAXN] = { 0 };
int C[MAXN] = { 0 };
int f[MAXN] = { 0 };
int n = 0; int s = 0;

int q[MAXN] = { 0 };
void dp(){
	int l = 1, r = 1; q[1] = 0;
	for(int i = 1; i <= n; i++){
		while(l < r and (f[q[l + 1]] - f[q[l]]) <= (s + T[i]) * (C[q[l + 1]] - C[q[l]]) ) l++;
		f[i] = f[q[l]] - (s + T[i]) * C[q[l]] + T[i] * C[i] + s * C[n];
		while(l < r and (f[q[r]] - f[q[r - 1]]) * (C[i] - C[q[r]]) >= (f[i] - f[q[r]]) * (C[q[r]] - C[q[r - 1]])) r--;
		q[++r] = i;
	}
}

signed main(){
	n = in; s = in;
	for(int i = 1; i <= n; i++) t[i] = in, c[i] = in;
	for(int i = 1; i <= n; i++) T[i] = T[i - 1] + t[i], C[i] = C[i - 1] + c[i];
	memset(f, 0x3f, sizeof(f)); f[0] = 0; dp();
	cout << f[n] << '\n';
	return 0;
}