#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0; int s = 0;

int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };
int tot = 0;

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int  dis[MAXN] = { 0 };
bool vis[MAXN] = { 0 };
priority_queue<pair<int, int> > q;

void dijkstra(int node){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[node] = 0;
	q.push(make_pair(0, node));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
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
		int x = 0; int y = 0; int w = 0;
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
