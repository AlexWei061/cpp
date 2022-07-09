#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 2 * MAXN
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define MOD mod
#define endl '\n'

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int r = 0; int mod = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int  dep[MAXN] = { 0 };
int   fa[MAXN] = { 0 };
int size[MAXN] = { 0 };
int  son[MAXN] = { 0 };
void dfs1(int x, int father, int depth){
	dep[x] = depth; fa[x] = father; size[x] = 1;
	for(int e = first[x]; e;e = nxt[e]){
		int y = to[e];
		if(y != father){
			dfs1(y, x, depth + 1);
			size[x] += size[y];
			if(size[y] > size[son[x]]) son[x] = y;
		}
	}
}

int cnt = 0;
int top[MAXN] = { 0 };
int idx[MAXN] = { 0 };
int  nv[MAXN] = { 0 };
void dfs2(int x, int t){
	top[x] = t; idx[x] = ++cnt; nv[cnt] = value[x];
	if(!son[x]) return;
	dfs2(son[x], t);
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa[x] and y != son[x]) dfs2(y, y);
	}
}

struct Tnode{
	int l, r;
	int dat;
	int lazy;
}t[MAXN * 4];

inline void pushup(int p){
	t[p].dat = t[ls(p)].dat + t[rs(p)].dat;
}
inline void pushdown(int p){
	if(t[p].lazy){
		t[ls(p)].lazy = (t[ls(p)].lazy + t[p].lazy) % MOD;
		t[rs(p)].lazy = (t[rs(p)].lazy + t[p].lazy) % MOD;
		t[ls(p)].dat = (t[ls(p)].dat + 1ll * t[p].lazy * (t[ls(p)].r - t[ls(p)].l + 1)) % MOD;
		t[rs(p)].dat = (t[rs(p)].dat + 1ll * t[p].lazy * (t[rs(p)].r - t[rs(p)].l + 1)) % MOD;
		t[p].lazy = 0;
	}
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = nv[l]; return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

void update(int p, int l, int r, int val){
	if(l <= t[p].l and t[p].r <= r){
		t[p].dat += val * (t[p].r - t[p].l + 1);
		t[p].lazy += val; return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) update(ls(p), l, r, val);
	if(r > mid)  update(rs(p), l, r, val);
	pushup(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1; int ans = 0;
	if(l <= mid) ans += query(ls(p), l, r);
	if(r > mid)  ans += query(rs(p), l, r);
	return ans % MOD;
}

int sumRange(int x, int y){
	int ans = 0; int fx = top[x]; int fy = top[y];
	while(fx != fy){
		if(dep[fx] >= dep[fy]){
			ans = (ans + query(1, idx[fx], idx[x])) % MOD;
			x = fa[fx]; fx = top[x];
		}
		else{
			ans = (ans + query(1, idx[fy], idx[y])) % MOD;
			y = fa[fy]; fy = top[y];
		}
	}
	if(idx[x] <= idx[y]) ans += query(1, idx[x], idx[y]);
	else ans += query(1, idx[y], idx[x]);
	return ans % MOD;
}

void modifyRange(int x, int y, int k){
	k %= MOD; int fx = top[x]; int fy = top[y];
	while(fx != fy){
		if(dep[fx] >= dep[fy]){
			update(1, idx[fx], idx[x], k);
			x = fa[fx]; fx = top[x];
		}
		else{
			update(1, idx[fy], idx[y], k);
			y = fa[fy]; fy = top[y];
		}
	}
	if(idx[x] <= idx[y]) update(1, idx[x], idx[y], k);
	else update(1, idx[y], idx[x], k);
}

int sumSon(int x){
	return query(1, idx[x], idx[x] + size[x] - 1) % MOD;
}

void modifySon(int x, int k){
	k %= MOD;
	update(1, idx[x], idx[x] + size[x] - 1, k);
}

int main(){
	n = in; m = in; r = in; mod = in;
	for(int i = 1; i <= n; i++) value[i] = in;
	for(int i = 1; i < n; i++){
		int x = in; int y = in;
		add(x, y); add(y, x);
	}
	dfs1(r, 0, 1); dfs2(r, r); build(1, 1, n);
	for(int i = 1; i <= m; i++){
		 int op = in;
		 if(op == 1){
		 	int x = in; int y = in; int k = in;
		 	modifyRange(x, y, k);
		 }
		 else if(op == 2){
		 	int x = in; int y = in;
		 	cout << sumRange(x, y) << endl;
		 }
		 else if(op == 3){
		 	int x = in; int k = in;
		 	modifySon(x, k);
		 }
		 else{
		 	 int x = in;
		 	 cout << sumSon(x) << endl;
		 }
	}
	return 0;
}
