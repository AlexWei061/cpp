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
bool bridge[MAXM] = { 0 };

void tarjan(int x, int edge){
	dfn[x] = low[x] = ++num;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y, e);
			low[x] = min(low[x], low[y]);
			if(dfn[x] < low[y]){
				bridge[e] = bridge[e ^ 1] = true;
			}
		}
		else if(e != (edge ^ 1)){
			low[x] = min(low[x], dfn[y]);
		}
	}
}

vector<int> dcc[MAXN];
int c[MAXN] = { 0 };
int cnt = 0;
void dfs(int x){                                // 遍历求点�?
	dcc[cnt].push_back(x); c[x] = cnt;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(c[y] or bridge[e]) continue;
		dfs(y);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i  = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}

	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i, 0);
	}

	for(int i = 1; i <= tot; i++){
		if(bridge[i]) printf("edge : %d to %d\n", to[i], to[i ^ 1]);
	}

	for(int i = 1; i <= n; i++){
		if(!c[i]){
			cnt++; dfs(i);
		}
	}

	for(int i = 1; i <= cnt; i++){
		printf("the %dth dcc includes : ", i);
		for(int j = 0; j < dcc[i].size(); j++){
			printf("%d ", dcc[i][j]);
		}
		puts("");
	}

	return 0;
}
