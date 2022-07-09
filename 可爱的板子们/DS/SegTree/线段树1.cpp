#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 100100
#define int long long

// P3372

int n = 0; int m = 0;
int a[MAXN] = { 0 };

struct SegTree{
	int l, r;
	int dat;
	int lazy;
}t[MAXN * 4];

inline int ls(int p){
	return p << 1;
}
inline int rs(int p){
	return p << 1 | 1;
}

inline void pushup(int p){
	t[p].dat = t[ls(p)].dat + t[rs(p)].dat;
}

inline void pushdown(int p){
	if(t[p].lazy){
		t[ls(p)].lazy += t[p].lazy; t[rs(p)].lazy += t[p].lazy;
		t[ls(p)].dat += (t[ls(p)].r - t[ls(p)].l + 1) * t[p].lazy;
		t[rs(p)].dat += (t[rs(p)].r - t[rs(p)].l + 1) * t[p].lazy;
		t[p].lazy = 0;
	}	
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = a[l]; return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

void update(int p, int l, int r, int val){
	if(l <= t[p].l and t[p].r <= r){
		t[p].lazy += val;
		t[p].dat += (t[p].r - t[p].l + 1) * val;
		return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) update(ls(p), l, r, val);
	if(r > mid)  update(rs(p), l, r, val);
	pushup(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r){
		return t[p].dat;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = 0;
	if(l <= mid) ans += query(ls(p), l, r);
	if(r > mid)  ans += query(rs(p), l, r);
	return ans;
}

signed main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int op = 0;
		scanf("%lld", &op);
		if(op == 1){
			int x, y, z;
			scanf("%lld%lld%lld", &x, &y, &z);
			update(1, x, y, z);
		}
		else if(op == 2){
			int x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0;
}
