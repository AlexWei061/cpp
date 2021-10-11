#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0;

// 原图的邻接表 
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
	
void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

// 缩点之后的邻接表
int tot2 = 0;
int first2[MAXN] = { 0 };
int   nxt2[MAXM] = { 0 };
int    to2[MAXM] = { 0 };
int   cdeg[MAXN] = { 0 };

void add2(int x, int y){
	nxt2[++tot2] = first2[x];
	first2[x] = tot2;
	to2[tot2] = y; cdeg[x]++;
}

int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };

int top = 0; 
int Stack[MAXN] = { 0 };
int   ins[MAXN] = { 0 };

int num = 0; int cnt = 0;
vector<int> scc[MAXN];
int c[MAXN] = { 0 };

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
	
	for(int i = 1; i <= n; i++){
		for(int j = first[i]; j; j = nxt[j]){
			int y = to[j];
			if(c[i] == c[y]){
				continue;
			}
			else{
				add2(c[i], c[y]);
			}
		}
	}
	
	int ans = 0; int a = 0; int idx = 0;
	for(int i = 1; i <= cnt; i++){
		if(!cdeg[i]){
			a++; idx = i;
		}
	}
	if(a == 1){
		ans += scc[idx].size();
		printf("%d\n", ans);
	}else{
		printf("%d\n", 0);
	}
	
	return 0;
}
