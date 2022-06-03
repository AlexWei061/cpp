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

int n = 0; int m = 0;
struct Table{
	
	int tot;
	int first[MAXN];
	int   nxt[MAXM];
	int    to[MAXM];
	
	inline void add(int x, int y){
		nxt[++tot] = first[x];
		first[x] = tot; to[tot] = y;
	}
	
}Tori, Tsimp;
int dep[MAXN] = { 0 };

int num = 0;
int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
int cut[MAXM] = { 0 };
void tarjan(int x, int edge){
	dfn[x] = low[x] = ++num;
	for(int e = Tori.first[x]; e; e = Tori.nxt[e]){
		int y = Tori.to[e];
		if(!dfn[y]){
			tarjan(y, e);
			low[x] = min(low[x], low[y]);
			if(dfn[x] < low[y]) cut[e] = cut[e ^ 1] = 1;
		}
		else if(e != (edge ^ 1)) low[x] = min(low[x], dfn[y]);
	}
}

int dcc = 0;
int c[MAXN] = { 0 };
void dfs(int x){
	c[x] = dcc;
	for(int e = Tori.first[x]; e; e = Tori.nxt[e]){
		int y = Tori.to[e];
		if(c[y] or cut[e]) continue;
		dfs(y);
	}
}

int main(){
	n = in; m = in; Tori.tot = 1; int ans = 0;
	for(int i = 1; i <= m; i++){
		int x = in, y = in;
		Tori.add(x, y); Tori.add(y, x);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
	for(int i = 1; i <= n; i++) if(!c[i]) dcc++, dfs(i);
//	for(int i = 1; i <= n; i++) cout << c[i] << ' '; puts("");
	for(int x = 1; x <= n; x++)
		for(int e = Tori.first[x]; e; e = Tori.nxt[e]){
			int y = Tori.to[e];
			if(!cut[e]) continue;
			Tsimp.add(c[x], c[y]); Tsimp.add(c[y], c[x]);
			dep[c[x]]++, dep[c[y]]++;
		}
//	for(int i = 1; i <= dcc; i++) cout << dep[i] << ' '; puts("");
	for(int i = 1; i <= dcc; i++) if(dep[i] == 2) ans++;
	cout << ((ans + 1) >> 1) << '\n';
	return 0;
}