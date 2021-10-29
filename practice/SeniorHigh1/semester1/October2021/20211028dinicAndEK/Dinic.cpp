#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30

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

int dep[MAXN] = { 0 };
int now[MAXM] = { 0 };
queue<int> q;

bool bfs(){
	memset(dep, 0, sizeof(dep));
	while(!q.empty()) q.pop();
	q.push(s); dep[s] = 1; now[s] = first[s];
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(value[e] and !dep[y]){
				q.push(y); now[y] = first[y];
				dep[y] = dep[x] + 1;
				if(y == t) return true;
			}
		}
	}
	return false;
}

int dinic(int x, int flow){
	if(x == t) return flow;
	int rest = flow; int e = 0;
	for(e = now[x]; e and rest; e = nxt[e]){
		int y = to[e];
		if(value[e] and dep[y] == dep[x] + 1){
			int k = dinic(y, min(rest, value[e]));
			if(!k) dep[y] = 0;
			value[e] -= k;
			value[e ^ 1] += k;
			rest -= k;
		}
	}
	now[x] = e;
	return flow - rest;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w); add(y, x, 0);
	}
	int flow = 0;
	while(bfs()){
		while(flow = dinic(s, INFI)) maxflow += flow;
	}
	printf("%d\n", maxflow);
	return 0;
} 
