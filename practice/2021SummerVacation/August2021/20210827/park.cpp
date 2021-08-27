#include<bits/stdc++.h>
using namespace std;

#define INFI 0x3f3f3f3f
#define MAXN 10010
#define MAXK MAXN * (MAXN - 1)

int n = 0, k = 0, t = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXK] = { 0 };
int    to[MAXK] = { 0 };
int value[MAXK] = { 0 };

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
	scanf("%d%d%d", &n, &k, &t);
	for(int i = 0; i < k; i++){
		int x = 0, y = 0, d = 0;
		scanf("%d%d%d", &x, &y, &d);
		add(x, y, d);
		add(y, x, d);
	}

	dijkstra(t);

	printf("%d\n", dis[n]);

	return 0;
}