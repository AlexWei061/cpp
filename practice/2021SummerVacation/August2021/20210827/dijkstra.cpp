#include<bits/stdc++.h>
using namespace std;

#define INFI 0x3f3f3f3f
#define MAXN 10010
#define MAXM MAXN * (MAXN - 1)

int n = 0/*点数*/, m = 0/*边数*/;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y, int v){
	nxt[++tot] = first[x]; first[x] = tot;
	to[tot] = y; value[tot] = v;
}

int  dis[MAXN] = { 0 };
bool isV[MAXN] = { 0 };
priority_queue<pair<int, int>> q;
void dijkstra(int node){                                        // 求出每个节点到 node 的最短近距离
	memset(dis, 0x3f, sizeof(dis));
	memset(isV, 0, sizeof(isV));
	dis[node] = 0;
	q.push(make_pair(0, node));                                 // 源点入队
	while(!q.empty()){
		int u = q.top().second;                                 // 取出队首节点编号
		q.pop();
		if(isV[u]){
			continue;
		}
		isV[u] = 1;                                             // 标记已经处理过
		for(int e = first[u]; e != 0; e = nxt[e]){              // 遍历这个节点所连的所有边
			int v = to[e];                                      // u -e-> v 
			if(dis[u] + value[e] < dis[v]){
				dis[v] = dis[u] + value[e];                     // 更新
				q.push(make_pair(-dis[v], v));                  // v 入队
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int x = 0, y = 0, v = 0;
		scanf("%d%d%d", &x, &y, &v);
		add(x, y, v);
		add(y, x, v);
	}

	dijkstra(1);

	for(int i = 1; i <= n; i++){
		printf("%d ", dis[i]);
	}
	puts("");

	return 0;
}