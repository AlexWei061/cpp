#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 2 * MAXN
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;

struct NxtTable{
	int tot = 0;
	int first[MAXN] = { 0 };
	int   nxt[MAXM] = { 0 };
	int    to[MAXM] = { 0 };
	
	inline void add(int x, int y){
		nxt[++tot] = first[x];
		first[x] = tot; to[tot] = y;
	}
}origin, opra;

bool vis[MAXN] = { 0 };
int size[MAXN] = { 0 };
int ans = INFI; int pos = 0;

void dfs(int x){
	vis[x] = 1; size[x] = 1;
	int max_part = 0;
	for(int e = opra.first[x]; e; e = opra.nxt[e]){
		int y = opra.to[e];
		if(vis[y]) continue;
		dfs(y);
		size[x] += size[y];
		max_part = max(max_part, size[y]); 
	} 
	max_part = max(n - size[x], max_part);
	if(max_part < ans){
		ans = max_part; pos = x;
	} 
}

int main(){
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	n = in; m = in;
	for(int i = 1; i < n; i++){
		int x = in; int y = in;
		origin.add(x, y); origin.add(y, x);
	}
	for(int i = 1; i <= m; i++){
		int x = in; int y = in;
	}
	return 0;
}
