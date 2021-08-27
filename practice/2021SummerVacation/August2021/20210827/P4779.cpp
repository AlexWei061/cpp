#include<bits/stdc++.h>
using namespace std;

#define INFI 0x3f3f3f3f
#define MAXN (int)1e5+100
#define MAXM (int)(2 * (10e5 + 100))

int n = 0; int m = 0; int s = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y, int v){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = v;
}

int  dis[MAXN] = { 0 };
bool isV[MAXN] = { 0 };
priority_queue<pair<int, int> > q;
void dijkstra(int node){
	memset(dis, 0x3f, sizeof(dis));
	memset(isV, 0, sizeof(isV));
	dis[node] = 0;
	q.push(make_pair(0, node));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(isV[u]){
			continue;
		}
		isV[u] = 1;
		for(int e = first[u]; e; e = nxt[e]){
			int v = to[e];
			if(dis[u] + value[e] < dis[v]){
				dis[v] = dis[u] + value[e];
				q.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < m; i++){
		int u = 0, v = 0, w = 0;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}

	dijkstra(s);

	for(int i = 1; i <= n; i++){
		printf("%d ", dis[i]);
	}
	puts("");

	return 0;
}