#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 1001000
#define MAXM 2 * MAXN
 
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
 
int ans = 0;
int f1[MAXN] = { 0 };
int f2[MAXN] = { 0 };
 
void dp(int x, int fa){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa){
			continue;
		}
		dp(y, x);
		if(f1[x] < f1[y] + value[e]){
			f2[x] = f1[x];
			f1[x] = f1[y] + value[e];
		}
		else if(f2[x] < f1[y] + value[e]){
			f2[x] = f1[y] + value[e];
		}
		ans = max(ans, f1[x] + f2[x]); 
	}
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n-1; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w); add(y, x, w);
	}
	
	dp(1, 0);
	
	printf("%d\n", ans);
	
	return 0;
}
