#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

                   /*   1  2  3  4  5  6   7   */  
int   ctimed[10] = { 0, 2, 6, 4, 8, 6, 10, 14 };
bool isHaveS[10] = { 0 };
int start = 0, end = 0, m = 0;

int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
int value[MAXN] = { 0 };
int tot = 0;

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int  dis[MAXN] = { 0 };
bool isV[MAXN] = { 0 };
priority_queue<pair<int, int> > q;

/*

runtime complexity : O(mlog(n+m))

*/

void dijkstra(int node){
	memset(dis, 0x3f, sizeof(dis));
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
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	for(int i = 1; i <= 7; i++){
		scanf("%d", &isHaveS[i]);
	}
	/*
	for(int i = 1; i <= 7; i++){
		printf("%d ", isHaveS[i]);
	}
	puts("");
	*/
	
	scanf("%d%d", &start, &end);
	//printf("s = %d e = %d\n", start, end);
	
	scanf("%d", &m);
	//printf("m = %d\n", m);
	
	for(int i = 0; i < m; i++){
		int u = 0, v = 0, k = 0;
		scanf("%d%d%d", &u, &v, &k);
		if(isHaveS[k]){
			add(u, v, ctimed[k]/2);
			add(v, u, ctimed[k]/2);
		}
		else{
			add(u, v, ctimed[k]);
			add(v, u, ctimed[k]);
		}
	}
	
	dijkstra(start);
	
	/*
	for(int i = 1; i <= 4; i++){
		for(int e = first[i]; e; e = nxt[e]){
			printf("%d to %d v = %d\n", i, to[e], value[e]);
		}
		puts("");	
	}
	
	for(int i = 0; i <= 4; i++){
		printf("%d ", dis[i]);
	}
	puts("");
	*/
	
	printf("%d\n", dis[end]);
	
	
	return 0;
}
