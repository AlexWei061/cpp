#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

// P3388
/* cut-vertex : 割点 */

int n = 0; int m = 0;
int root = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

void add(int x,  int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int  dfn[MAXN] = { 0 };
int  low[MAXN] = { 0 };
bool cut[MAXN] = { 0 };
int num = 0;  int cnt = 0;

void tarjan(int x){
	 dfn[x] = low[x] = ++num;
	 int flag = 0;
	 for(int e = first[x]; e; e = nxt[e]){
	 	int y = to[e];
	 	if(!dfn[y]){
	 		tarjan(y);
	 		low[x] = min(low[x], low[y]);
	 		if(dfn[x] <= low[y]){
	 			flag++;
	 			if(x != root or flag > 1){
	 				cut[x] = true;
				}
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
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		if(x == y) continue;
		add(x, y); add(y, x);
	}
	
	for(int i = 1; i <= n; i ++){
		if(!dfn[i]){
			root = i;
			tarjan(i);
		}
	}
	
	int a = 0;
	for(int i = 1; i <= n; i++){
		if(cut[i]){
			a++;
			//printf("%d ", i);
		}
	}
	printf("%d\n", a);
	for(int i = 1; i <= n; i++){
		if(cut[i]){
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}