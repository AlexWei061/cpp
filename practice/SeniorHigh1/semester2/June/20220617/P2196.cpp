#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 101
#define MAXM 1010

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
int g[MAXN][MAXN] = { 0 };
int pre[MAXN] = { 0 };
int f[MAXN] = { 0 };

void print(int x){
	if(!pre[x]) { cout << x; return; }
	print(pre[x]);
	cout << ' ' << x;
}

int main(){
	n = in; int t = 0; int ans = 0;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n - 1; i++)
		for(int j = i + 1; j <= n; j++)
			if(in) g[i][j] = g[j][i] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(g[i][j] and f[j] > f[i]) f[i] = f[j], pre[i] = j;
		f[i] += a[i];
		if(f[i] > ans) ans = f[i], t = i;
	}
	print(t);
	cout << '\n' << ans << '\n';
	end : return 0;
}