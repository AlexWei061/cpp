#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN

// P3385

int t = 0;
int n = 0; int m = 0;

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

int dis[MAXN] = { 0 };
int vis[MAXN] = { 0 };
int cnt[MAXN] = { 0 };
queue<int> q;

void SPFA(){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	dis[1] = 0; vis[1] = 1; q.push(1);
	while(!q.empty()){
		int x = q.front();
		vis[x] = 0; q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(dis[y] > dis[x] + value[e]){
				dis[y] = dis[x] + value[e];
				cnt[y] = cnt[x] + 1;
				if(!vis[y]){
					if(cnt[y] >= n){
						printf("YES\n"); return;
					}
					vis[y] = 1; q.push(y);
				}
			}
		}
	}
	printf("NO\n");
}

int main(){
	scanf("%d", &t);
	while(t--){
		tot = 0;
		memset(first, 0, sizeof(first));
		memset(nxt, 0, sizeof(nxt));
		memset(to, 0, sizeof(to));
		memset(value, 0, sizeof(value));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++){
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			if(w >= 0){
				add(x, y, w); add(y, x, w);
			}
			else{
				add(x, y, w);
			}
		}
		SPFA();
	}
	return 0;
}