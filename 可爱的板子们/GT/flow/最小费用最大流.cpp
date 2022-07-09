#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30

int ans = 0;
int maxflow = 0;
int n = 0; int m = 0;
int s = 0; int t = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };
int  cost[MAXM] = { 0 };

inline void add(int x, int y, int w, int c){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = w; cost[tot] = c;
}

int dis[MAXN] = { 0 };
int inf[MAXN] = { 0 };
int pre[MAXN] = { 0 };
int vis[MAXN] = { 0 };

bool SPFA(){
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push(s); dis[s] = 0; vis[s] = 1;
	inf[s] = INFI;
	while(!q.empty()){
		int x = q.front(); vis[x] = 0; q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			if(!value[e]) continue;
			int y = to[e];
			if(dis[y] > dis[x] + cost[e]){
				dis[y] = dis[x] + cost[e];
				inf[y] = min(inf[x], value[e]);
				pre[y] = e;
				if(!vis[y]){ vis[y] = 1; q.push(y); }
			}
		}
	}
	if(dis[t] == 0x3f3f3f3f) return false;
	else return true;
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
	ans += dis[t] * inf[t];
}

int main(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int x, y, w, c;
		scanf("%d%d%d%d", &x, &y, &w, &c);
		add(x, y, w, c); add(y, x, 0, -c);
	}
	while(SPFA()) update();
	printf("%d %d\n", maxflow, ans);
	return 0;
}
