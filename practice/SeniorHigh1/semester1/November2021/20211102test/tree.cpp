#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500
#define MAXM 2 * MAXN
#define int long long

int n = 0; int k = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int dep[MAXN] = { 0 };
int f[MAXN][50] = { 0 };
void preworkLCA(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = 0; i <= 30; i++){
		f[x][i+1] = f[f[x][i]][i];
	}
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa){
			f[y][0] = x;
			preworkLCA(y, x);
		}
	}
}

int queryLCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 30; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 30; i >= 0; i--)
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	return f[x][0];
}

int queryDis(int x, int y){
	return dep[x] + dep[y] - 2 * dep[queryLCA(x, y)];
}

signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &value[i]);
	}
	for(int i = 1; i < n; i++){
		int x, y; scanf("%lld%lld", &x, &y);
		add(x, y); add(y, x);
	}
	
	preworkLCA(1, 0);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(queryDis(i, j) <= k) ans += value[i] ^ value[j];
		}
	}
	printf("%lld\n", ans / 2);
	
	return 0;
}
