#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN

// P4779

int s = 0;
int n = 0; int m = 0;

int tot = 0;
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

int dis[MAXN] = { 0 };
int vis[MAXN] = { 0 };
priority_queue<pair<int, int> > q;

void dijkstra(int node){
	memset(dis, 0x3f, sizeof(dis));
	dis[node] = 0; q.push(make_pair(0, node));
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int e = first[u]; e; e = nxt[e]){
			int v = to[e];
			if(dis[v] > dis[u] + value[e]){
				dis[v] = dis[u] + value[e];
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= m; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
	}
	dijkstra(s);
	for(int i = 1; i <= n; i++){
		printf("%d ", dis[i]);
	}
	puts("");
	return 0;
}