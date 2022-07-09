#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0;
int root = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };

int top = 0;
int Stack[MAXN] = { 0 };

int num = 0; int cnt = 0;
int cut[MAXN] = { 0 };
vector<int> dcc[MAXN];

void tarjan(int x){
	dfn[x] = low[x] = ++num;
	Stack[++top] = x;
	if(x == root and first[x] == 0){
		dcc[++cnt].push_back(x); return;
	}
	int flag = 0;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if(dfn[x] <= low[y]){
				flag++;
				if(x != root or flag > 1)
					cut[x] = true;
				cnt++; int z = 0;
				do{
					z = Stack[top--];
					dcc[cnt].push_back(z);
				}while(z != y);
				dcc[cnt].push_back(x);
			}
		}
		else{
			low[x] = min(low[x], dfn[y]);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}

	for(int i = 1;  i <= n; i++)
		if(!dfn[i]){
			root = i; tarjan(i);
		}

	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}

	for(int i = 1; i <= n; i++){
		if(cut[i])
			printf("%d ", i);
	}
	puts("are cut-vertexes");

	for(int i = 1; i <= cnt; i++){
		printf("the %dth dcc includes : ", i);
		for(int j = 0; j < dcc[i].size(); j++){
			printf("%d ", dcc[i][j]);
		}
		puts("");
	}

	return 0;
}

