#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30
#define int long long

int maxflow = 0;
int n = 0; int m = 0;
int s = 0; int t = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int vis[MAXN] = { 0 };
int inf[MAXN] = { 0 };
int pre[MAXN] = { 0 };

bool bfs(){
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	inf[s] = INFI;
	vis[s] = 1; q.push(s);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e])
			if(value[e]){
				int y = to[e];
				if(vis[y]) continue;
				inf[y] = min(inf[x], value[e]);
				pre[y] = e;
				vis[y] = 1; q.push(y);
				if(y == t) return true;
			}
	}
	return false;
}

void update(){
	int x = t;
	while(x != s){
		int e = pre[x];
		value[e] -= inf[t];
		value[e ^ 1] += inf[t];
		x = to[e ^ 1];
	}
	maxflow += inf[t];
}

signed main(){
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%lld%lld%lld", &x, &y, &w);
		add(x, y, w); add(y, x, 0);
	}
	
	while(bfs()) update();
	printf("%lld\n", maxflow);
	
	return 0;
}
