#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 1001000
#define ls(p) p << 1
#define rs(p) p << 1 | 1
const int INFI = 1e18;

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
int n = 0; int q = 0;

struct Tnode{
	int l, r;
	int dat;
	int lazy1, lazy2;
}t[MAXN * 4];

inline void up(int p) { t[p].dat= max(t[ls(p)].dat, t[rs(p)].dat); }
inline void mktag1(int p, int x) { t[p].dat = t[p].lazy1 = x; t[p].lazy2 = 0; }
inline void mktag2(int p, int x){
	t[p].dat += x;
	if(t[p].lazy1 != INFI) t[p].lazy1 += x;
	else t[p].lazy2 += x;
}
inline void down(int p){
	if(t[p].lazy1 != INFI){
		mktag1(ls(p), t[p].lazy1);
		mktag1(rs(p), t[p].lazy1);
		t[p].lazy1 = INFI;
	}
	else if(t[p].lazy2){
		mktag2(ls(p), t[p].lazy2);
		mktag2(rs(p), t[p].lazy2);
		t[p].lazy2 = 0;
	}
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	t[p].lazy1 = INFI; t[p].lazy2 = 0;
	if(l == r) { t[p].dat = a[l]; return; }
	int mid = (l + r) >> 1;
	build(ls(p), l, mid); build(rs(p), mid + 1, r);
	up(p);
}

void update(int p, int l, int r, int x, int op){
	if(l <= t[p].l and t[p].r <= r){
		if(op == 1) mktag1(p, x);
		if(op == 2) mktag2(p, x);
		return;
	} down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) update(ls(p), l, r, x, op);
	if(r > mid) update(rs(p), l, r, x, op);
	up(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	down(p);
	int mid = (t[p].l + t[p].r) >> 1; int ans = -INFI;
	if(l <= mid) ans = max(ans, query(ls(p), l, r));
	if(r > mid) ans = max(ans, query(rs(p), l, r));
	return ans;
}

signed main(){
	n = in; q = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	build(1, 1, n);
	while(q--){
		int op = in; int l = in; int r = in;
		if(op != 3){
			int x = in;
			update(1, l, r, x, op);
		}
		else cout << query(1, l, r) << '\n';
	}
	return 0;
}