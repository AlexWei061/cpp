#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 4 * MAXN

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int k = 0;
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int dep[MAXN] = { 0 };
int f[MAXN][35] = { 0 };
void prework(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = 0; i <= 20; i++) f[x][i + 1] = f[f[x][i]][i];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		f[y][0] = x;
		prework(y, x);
	}
}

int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}

int ans = 0;
void dfs(int x, int fa){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		dfs(y, x);
		value[x] += value[y];	
	}
	ans = max(ans, value[x]);
}

int main(){
	n = in; k = in;
	for(int i = 1; i < n; i++){
		int x = in, y = in;
		add(x, y); add(y, x);
	} prework(1, 0);
	for(int i = 1; i <= k; i++){
		int x = in; int y = in;
		int lca = LCA(x, y);
		value[x]++, value[y]++;
		value[lca]--, value[f[lca][0]]--;
	} dfs(1, 0);
	cout << ans << '\n';
	return 0;
}