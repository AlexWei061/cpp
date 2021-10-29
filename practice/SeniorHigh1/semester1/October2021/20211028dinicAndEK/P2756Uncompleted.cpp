#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30

// 怎么输出方案？？ 

int maxflow = 0;
int n = 0; int m = 0;
int s = 0; int t = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

inline void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int pre[MAXN] = { 0 };
int vis[MAXN] = { 0 };
int inf[MAXN] = { 0 };

bool bfs(){
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	vis[s] = 1; q.push(s);
	inf[s] = INFI;
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

int main(){
	scanf("%d%d", &m, &n);
	s = 0; t = n + 1;
	for(int i = 1; i <= n; i++){
		add(i+n, t, 1); add(t, i+n, 0);
	}
	for(int i = 1; i <= m; i++){
		add(s, i, 1); add(i, s, 0);
	}
	while(true){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == -1 and y == -1) break;
		add(x, y+n, 1); add(y+n, x, 0);
	}
	while(bfs()){
		update();
	}
	printf("%d\n", maxflow);
	return 0;
}
