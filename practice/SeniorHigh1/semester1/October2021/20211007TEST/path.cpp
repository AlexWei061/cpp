#include<bits/stdc++.h>
using namespace std;

#define MAXN 11000000
#define ll long long

int n = 0;
int q = 0; int k = 0;

int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
int value[MAXN] = { 0 };
int tot = 0;

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

ll f[MAXN] = { 0 };

void dfs(int x, int fa){
	//printf("x = %d\n", x);
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa){
			f[y] = f[x] + value[e];
			dfs(y, x);
		}
	}
}

int main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);

	scanf("%d", &n);
	//printf("n = %d\n", n);

	for(int i = 1; i < n; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}

	scanf("%d%d", &q ,&k);
		
	dfs(k, 0);
	for(int i = 1; i <= q; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		printf("%lld\n", f[x] + f[y]);
	}

    return 0;
}