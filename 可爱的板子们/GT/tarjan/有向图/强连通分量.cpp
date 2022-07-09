#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int   dfn[MAXN] = { 0 };
int   low[MAXN] = { 0 };

int Stack[MAXN] = { 0 };
int ins[MAXN] = { 0 };
int c[MAXN] = { 0 };
vector<int> scc[MAXN];

int n = 0; int m = 0;
int num = 0; int top = 0; int cnt = 0;

void tarjan(int x){
	dfn[x] = low[x] = ++num;
	Stack[++top] = x; ins[x] = 1;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]){
			low[x] = min(low[x], dfn[y]);
		}
	}
	if(dfn[x] == low[x]){
		cnt++; int y = 0;
		do{
			y = Stack[top--]; ins[y] = 0;
			c[y] = cnt; scc[cnt].push_back(y);
		}while(x != y);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	
	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	
	for(int i = 1; i <= cnt; i++){
		printf("the %dth scc includes : ", i);
		for(int j = 0; j < scc[i].size(); j++){
			printf("%d ", scc[i][j]);
		}
		puts("");
	}
	
	return 0;
}
