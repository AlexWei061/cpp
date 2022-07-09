#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 400400
#define MAXM 4 * MAXN
#define INFI 0x7f7f7f7f7f7f7f7f

inline int read() {
	int x = 0;
	char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9') {
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

inline void add(int x, int y, int weight) {
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	value[tot] = weight;
}

struct Tedge {
	int x, y;
	int val, used;
	bool operator < (const Tedge &rhs) const {
		return val < rhs.val;
	}
} edge[MAXM];

int ans = 0;
int n = 0;
int m = 0;
int fa[MAXN] = { 0 };

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void kruskal() {
	for(int i = 1; i <= m; i++) {
		Tedge e = edge[i];
		int x = e.x; int y = e.y;
		int fax = find(x); int fay = find(y);
		if(fax == fay) continue;
		add(x, y, e.val); add(y, x, e.val);
		ans += e.val, edge[i].used = 1, fa[fay] = fax;
	}
}

int f[MAXN][25] = { 0 };           // 祖先
int mx[MAXN][25] = { 0 };          // 最大值
int mm[MAXN][25] = { 0 };          // 次大值
int dep[MAXN] = { 0 };

void dfs(int x) {
	dep[x] = dep[f[x][0]] + 1;
	for(int i = 1; i <= 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		if(mx[x][i - 1] == mx[f[x][i - 1]][i - 1]) {
			mx[x][i] = mx[x][i - 1];
			mm[x][i] = max(mm[f[x][i - 1]][i - 1], mm[x][i - 1]);
		}
		if(mx[x][i - 1] > mx[f[x][i - 1]][i - 1]) {
			mx[x][i] = mx[x][i - 1];
			mm[x][i] = max(mx[f[x][i - 1]][i - 1], mm[x][i - 1]);
		}
		if(mx[x][i - 1] < mx[f[x][i - 1]][i - 1]) {
			mx[x][i] = mx[f[x][i - 1]][i - 1];
			mm[x][i] = max(mx[x][i - 1], mm[f[x][i - 1]][i - 1]);
		}
	}
	for(int e = first[x]; e; e = nxt[e]) {
		int y = to[e];
		if(y == f[x][0]) continue;
		f[y][0] = x; mx[y][0] = value[e];
		dfs(y);
	}
}

int queryLca(int x, int y) {
	if(dep[y] > dep[x]) swap(x, y);
	for(int i = 20; i >= 0; i--) {
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20; i >= 0; i--) {
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

int solve(int x, int y, int w) {
	int lca = queryLca(x, y);
	int numx = 0; int numm = 0;
	for(int i = 20; i >= 0; i--) {
		if(dep[f[x][i]] >= dep[lca]) {
			if(numx == mx[x][i]) numm = max(numm, mm[x][i]);
			if(numx > mx[x][i]) numm = max(numm, mx[x][i]);
			if(numx < mx[x][i]) 
				numx = mx[x][i], numm = max(numm, mm[x][i]);
			x = f[x][i];
		}
		if(dep[f[y][i]] >= dep[lca]) {
			if(numx == mx[y][i]) numm = max(numm, mm[y][i]);
			if(numx > mx[y][i]) numm = max(numm, mx[y][i]);
			if(numx < mx[y][i]) 
				numx = mx[y][i], numm = max(numm, mm[y][i]);
			y = f[y][i];
		}
	}
	if(w != numx) return ans - numx + w;
	else if(numm) return ans - numm + w;
	else return INFI;
}

signed main() {
	n = in; m = in;
	for(int i = 1; i <= m; i++) {
		edge[i].x = in; edge[i].y = in;
		edge[i].val = in; edge[i].used = 0;
	}
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= n; i++) fa[i] = i;
	kruskal(); dfs(1);
	int res = INFI;
	for(int i = 1; i <= m; i++) {
		Tedge e = edge[i];
		if(!e.used) res = min(res, solve(e.x, e.y, e.val));
	}
	cout << res << '\n';
	return 0;
}
