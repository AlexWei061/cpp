#include<bits/stdc++.h>
using namespace std;

#define INFI (long long)1 << 60
#define MAXN 500500
#define MAXM 500500

int m = 0;
int a, b, c, d, e;

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

long long edgemin[10][10] = { 0 };

long long  dis[MAXN] = { 0 };
bool vis[MAXN] = { 0 };
priority_queue<pair<long long, int> > q;
void dijkstra(int node){
	fill(dis, dis+a+b+c+d+e+1, INFI);
	memset(vis, 0, sizeof(vis));
	dis[node] = 0;
	q.push(make_pair(0, node));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
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
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		add(l - 1, r, r - l + 1);
		add(r, l - 1, r - l + 1);
	}
	
	dijkstra(a);
	edgemin[1][1] = dis[a];
	edgemin[1][2] = dis[a+b];
	edgemin[1][3] = dis[a+b+c];
	edgemin[1][4] = dis[a+b+c+d];
	
	dijkstra(a+b);
	edgemin[2][1] = dis[a];
	edgemin[2][2] = dis[a+b];
	edgemin[2][3] = dis[a+b+c];
	edgemin[2][4] = dis[a+b+c+d];
	
	dijkstra(a+b+c);
	edgemin[3][1] = dis[a];
	edgemin[3][2] = dis[a+b];
	edgemin[3][3] = dis[a+b+c];
	edgemin[3][4] = dis[a+b+c+d];
	
	dijkstra(a+b+c+d);
	edgemin[4][1] = dis[a];
	edgemin[4][2] = dis[a+b];
	edgemin[4][3] = dis[a+b+c];
	edgemin[4][4] = dis[a+b+c+d];
	
	long long ans = INFI;
	ans = min(ans, edgemin[1][2] + edgemin[3][4]);
	ans = min(ans, edgemin[1][3] + edgemin[2][4]);
	ans = min(ans, edgemin[1][4] + edgemin[2][3]);
	if(ans < INFI){
	    printf("%lld\n", ans);	
		
	}
	else{
		printf("-1\n");
	}
	
	return 0;
}
