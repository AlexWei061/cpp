#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXM 5 * MAXN
#define INFI 1 << 30

int ans = 0;
int maxflow = 0;
int s = 0; int t = 0;
int n = 0; int k = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };
int  cost[MAXM] = { 0 };

inline void add(int x, int y, int w, int c){
	nxt[++tot] = first[x]; first[x] = tot;
	to[tot] = y; value[tot] = w; cost[tot] = c;
	nxt[++tot] = first[y]; first[y] = tot;
	to[tot] = x; value[tot] = 0; cost[tot] = -c;
}

int dis[MAXN] = { 0 };
int vis[MAXN] = { 0 };
int pre[MAXN] = { 0 };
int inf[MAXN] = { 0 };

bool SPFA(){
	printf("in\n");
	queue<int> q;
	memset(dis, 0xcf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push(s); vis[s] = 1; dis[s] = 0;
	inf[s] = INFI;
	while(!q.empty()){
		int x = q.front(); vis[x] = 0; q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			if(!value[e]) continue;
			int y = to[e];
			if(dis[y] < dis[x] + cost[e]){
				dis[y] = dis[x] + cost[e];
				inf[y] = min(inf[x], value[e]);
				pre[y] = e;
				if(!vis[y]){ vis[y] = 1; q.push(y); }
			}
		}
	}
	if(dis[t] == 0xcfcfcfcf) return false;
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

inline solve(int i, int j, int k){
	return (i - 1) * n + j + k * n * n;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= n; j++){
			int c; scanf("%d", &c);
			add(solve(i, j, 0), solve(i, j, 1), 1, c);
			add(solve(i, j, 0), solve(i, j, 1), k - 1, 0);
			if(j < n) add(solve(i, j, 1), solve(i, j + 1, 0), k, 0);
			if(i < n) add(solve(i, j, 1), solve(i + 1, j, 0), k, 0);
		}
	}
	while(SPFA()) update();
	printf("%d\n", ans);
	return 0;
}
