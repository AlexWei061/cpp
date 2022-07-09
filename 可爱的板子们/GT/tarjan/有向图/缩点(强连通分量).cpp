#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 10100
#define MAXM 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int dat[MAXN] = { 0 };
struct Table{
	
	int tot;
	int first[MAXN] = { 0 };
	int   nxt[MAXM] = { 0 };
	int    to[MAXM] = { 0 };
	
	inline void add(int x, int y){
		nxt[++tot] = first[x];
		first[x] = tot; to[tot] = y;
	}
	
}Tori, Tsimp;
int val[MAXN] = { 0 };
int dep[MAXN] = { 0 };

int num = 0, cnt = 0;
int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
int top = 0;
int stk[MAXN] = { 0 };
int ins[MAXN] = { 0 };
vector<int> scc[MAXN];
int c[MAXN] = { 0 };
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	stk[++top] = x; ins[x] = 1;
	for(int e = Tori.first[x]; e; e = Tori.nxt[e]){
		int y = Tori.to[e];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x]){
		cnt++; int y = 0; int v = 0;
		do{
			y = stk[top--]; ins[y] = 0;
			c[y] = cnt; scc[cnt].push_back(y); v += dat[y];
		}while(x != y); val[cnt] = v;
	}
}

int dis[MAXN] = { 0 };
int bfs(){
	int ans = 0; queue<int> q;
	for(int i = 1; i <= cnt; i++){
		dis[i] = val[i]; if(!dep[i]) q.push(i);
	}
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = Tsimp.first[x]; e; e = Tsimp.nxt[e]){
			int y = Tsimp.to[e];
			dis[y] = max(dis[y], dis[x] + val[y]);
			if(!--dep[y]) q.push(y);
		}
	}
	for(int i = 1; i <= cnt; i++) ans = max(ans, dis[i]);
	return ans;
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) dat[i] = in;
	for(int i = 1; i <= m; i++) { int x = in, y = in; Tori.add(x, y); }
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for(int x = 1; x <= n; x++)
		for(int e = Tori.first[x]; e; e = Tori.nxt[e]){
			int y = Tori.to[e];
			if(c[x] == c[y]) continue;
			Tsimp.add(c[x], c[y]); dep[c[y]]++;
		}
	cout << bfs() << '\n';
	return 0;
}
