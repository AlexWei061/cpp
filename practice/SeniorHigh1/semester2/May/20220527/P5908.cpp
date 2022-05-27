#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 2 * MAXN

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int   dep[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int n = 0; int d = 0;

void dfs(int x, int fa){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}

int main(){
	n = in; d = in; int ans = 0;
	for(int i = 1; i < n; i++){
		int x = in; int y = in; add(x, y); add(y, x);
	}
	dfs(1, 0);
	for(int i = 2; i <= n; i++) if(dep[i] <= d) ans++;
	cout << ans << '\n';
	return 0;
}