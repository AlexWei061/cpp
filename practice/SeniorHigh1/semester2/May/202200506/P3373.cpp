#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 100100
#define ls(p) p << 1
#define rs(p) p << 1 | 1

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int a[MAXN] = { 0 };
int n = 0; int m = 0; int mod = 0;
struct Tnode{
	int l, r;
	int dat;
	int add, mul;
}t[MAXN * 4];

inline void up(int p) { t[p].dat = (t[ls(p)].dat % mod + t[rs(p)].dat % mod) % mod; }
inline void down(int p){
	t[ls(p)].dat = 1ll * (t[p].mul * t[ls(p)].dat + ((t[ls(p)].r - t[ls(p)].l + 1) * t[p].add) % mod) % mod;
	t[rs(p)].dat = 1ll * (t[p].mul * t[rs(p)].dat + ((t[rs(p)].r - t[rs(p)].l + 1) * t[p].add) % mod) % mod;
	t[ls(p)].mul = 1ll * (t[ls(p)].mul % mod * t[p].mul % mod) % mod;
	t[rs(p)].mul = 1ll * (t[rs(p)].mul % mod * t[p].mul % mod) % mod;
	t[ls(p)].add = 1ll * (t[ls(p)].add % mod * t[p].mul % mod + t[p].add) % mod;
	t[rs(p)].add = 1ll * (t[rs(p)].add % mod * t[p].mul % mod + t[p].add) % mod;
	t[p].mul = 1; t[p].add = 0;
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r; t[p].mul = 1;
	if(l == r) { t[p].dat = a[l] % mod; return; }
	int mid = (l + r) >> 1;
	build(ls(p), l, mid); build(rs(p), mid + 1, r);
	up(p);
}

void add(int p, int l, int r, int x){
	if(l <= t[p].l and t[p].r <= r){
		t[p].add = (t[p].add % mod + x % mod) % mod;
		t[p].dat = 1ll * (t[p].dat + (x * (t[p].r - t[p].l + 1)) % mod) % mod;
		return;
	}
	down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) add(ls(p), l, r, x);
	if(r > mid)  add(rs(p), l, r, x);
	up(p);
}

void mul(int p, int l, int r, int x){
	if(l <= t[p].l and t[p].r <= r){
		t[p].add = (t[p].add % mod * x % mod) % mod;
		t[p].mul = (t[p].mul % mod * x % mod) % mod;
		t[p].dat = (t[p].dat % mod * x % mod) % mod;
		return;
	}
	down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) mul(ls(p), l, r, x);
	if(r > mid)  mul(rs(p), l, r, x);
	up(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	down(p);
	int mid = (t[p].l + t[p].r) >> 1; int ans = 0;
	if(l <= mid) ans = (ans % mod + query(ls(p), l, r) % mod) % mod;
	if(r > mid)  ans = (ans % mod + query(rs(p), l, r) % mod) % mod;
	return ans;
}

signed main(){
	n = in; m = in; mod = in;
	for(int i = 1; i <= n; i++) a[i] = in % mod;
	build(1, 1, n);
	while(m--){
		int op = in; int l = in; int r = in;
		if(op == 1){
			int x = in;
			mul(1, l, r, x);
		}
		else if(op == 2){
			int x = in;
			add(1, l, r, x);
		}
		else cout << query(1, l, r) << '\n';
	}
	return 0;
}