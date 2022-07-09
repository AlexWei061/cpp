#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int num = 0;
int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
int bridge[MAXM] = { 0 };

void tarjan(int x, int edge){
	dfn[x] = low[x] = ++num;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y, e);
			low[x] = min(low[x], low[y]);
			if(dfn[x] < low[y])
				bridge[e] = bridge[e ^ 1] = true;
		}
		else if(e != (edge ^ 1)){
			low[x] = min(low[x], dfn[y]);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	
	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			tarjan(i, 0);
		}
	}
	
	for(int i = 2; i < tot; i++){
		if(bridge[i]) printf("bridge : %d %d\n", to[i], to[i ^ 1]);
	}
	return 0;
}
