#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30
#define int long long

int ans = 0;
int maxflow = 0;
int s = 0; int t = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };
int  cost[MAXM] = { 0 };

inline void add(int x, int y, int w, int c){
	nxt[++tot] = first[x]; first[x] = tot; to[tot] = y; value[tot] = w; cost[tot] = c;
	nxt[++tot] = first[y]; first[y] = tot; to[tot] = x; value[tot] = 0; cost[tot] = -c;
}

int inf[MAXN] = { 0 };
int pre[MAXN] = { 0 };
int dis[MAXN] = { 0 };
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
	if(dis[t] == 0x3f3f3f3f3f3f3f3f) return false;
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

int day = 0;
int p = 0;
int a = 0; int f = 0;
int b = 0; int m = 0;

signed main(){
	scanf("%lld", &day);
	s = 0; t = 2 * day + 1;
	for(int i = 1; i <= day; i++){
		int temp = 0; scanf("%lld", &temp);
		add(s, i, temp, 0);
		add(i + day, t, temp, 0);
	}
	scanf("%lld%lld%lld%lld%lld", &p, &a, &f, &b, &m);
	for(int i = 1; i <= day; i++){
		add(s, i + day, INFI, p);
		if(i + 1 <= day) add(i, i + 1, INFI, 0);
		if(i + a <= day) add(i, i + day + a, INFI, f);
		if(i + b <= day) add(i, i + day + b, INFI, m);
	}
	while(SPFA()) update();
	printf("%lld\n", ans);
	return 0;
}
