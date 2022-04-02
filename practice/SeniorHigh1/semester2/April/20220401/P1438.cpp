#include<bits/stdc++.h>
using namespace std;
#define in read()
#define int long long
#define MAXN 500500
#define ls(p) p << 1
#define rs(p) p << 1 | 1

inline int read(){
	int f = 1; int x = 0; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-')f = -1; c = getchar(); }
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int n = 0; int m = 0;
int a[MAXN] = { 0 };
int c[MAXN] = { 0 };

struct SegTree{
	int l, r;
	int dat;
	int lazy;
}t[MAXN * 8];

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
	if(l == r) { t[p].dat = c[l]; return; }
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
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = 0;
	if(l <= mid) ans += query(ls(p), l, r);
	if(r > mid)  ans += query(rs(p), l, r);
	return ans;
}

signed main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) c[i] = a[i] - a[i - 1];
	build(1, 1, n + 1);
	for(int i = 1; i <= m; i++){
		int op = in;
		if(op == 1){
			int l = in; int r = in; int s = in; int d = in;
			int e = s + (r - l) * d;
			update(1, l, l, s);
			update(1, l + 1, r, d);
			update(1, r + 1, r + 1, -e);
		}
		if(op == 2){
			int p = in;
			cout << query(1, 1, p) << '\n';
		}
	}
	return 0;
}