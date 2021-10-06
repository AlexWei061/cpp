#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001000

int n = 0;
int ans = -1;

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

int f[MAXN] = { 0 };
void dfs(int x, int fa){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa){                                      // 避免往回搜
			f[y] = f[x] ^ value[e];
			dfs(y, x);
		}
	}
}

int trie[MAXN][10] = { 0 };
int cnt = 0;

void insert(int x){
	int p = 0;
	for(int i = 30; i >= 0; i--){
		int t = (x >> i) & 1;
		if(!trie[p][t]){
			trie[p][t] = ++cnt;
		}
		p = trie[p][t];
	}
}

int search(int x){
	int p = 0;
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		int t = (x >> i) & 1;
		if(trie[p][t^1]){
			p = trie[p][t^1];
			ans += (1 << i);
		}
		else{
			p = trie[p][t];
		}
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}

	dfs(1, 0);

	/*
	for(int i = 1; i <= n; i++){
		printf("%d ", f[i]);
	}
	puts("");
	*/

	for(int i = 1; i <= n; i++){
		insert(f[i]);
		ans = max(ans, search(f[i]));
	}
	printf("%d\n", ans);

	return 0;
}