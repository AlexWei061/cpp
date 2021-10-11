#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y , int weight){
	nxt[++tot] = first[x];
	first[x] = tot; 
	to[tot] = y;
	value[tot] = weight;
}

int p = 0; int ans = 0;
int dis[MAXN] = { 0 };
void dfs(int x, int fa){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa){
			continue;
		}
		dis[y] = dis[x] + value[e];
		if(ans < dis[y]){
			ans = dis[y];
			p = y;
		}
		dfs(y, x);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}
	
	ans = 0;
	dis[1] = 0;
	dfs(1, 0);
		
	ans = 0;
	dis[p] = 0;
	dfs(p, 0);
	
	printf("%d\n", ans);
	
	return 0;
}
