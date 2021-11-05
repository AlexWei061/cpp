#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500
#define INFI INT_MAX
#define endl '\n'

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int n = 0; int m = 0;

struct Tnode{
	int l, r;
	int dat;
	int lazy;
};
struct SegTree{
	#define ls(p) (p << 1)
	#define rs(p) (p << 1 | 1)
	Tnode t[4 * MAXN];
	int   a[MAXN];
	
	inline void pushup(int p){
		t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat);
	}
	
	inline void pushdown(int p){
		if(t[p].lazy){
			t[ls(p)].dat += t[p].lazy; t[rs(p)].dat += t[p].lazy;
			t[ls(p)].lazy += t[p].lazy; t[rs(p)].lazy += t[p].lazy;
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
			t[p].dat += val; t[p].lazy += val;
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
		int mid = (t[p].l + t[p].r) >> 1; int ans = -INFI;
		if(l <= mid) ans = max(ans, query(ls(p), l, r));
		if(r > mid)  ans = max(ans, query(rs(p), l, r));
		return ans;
	}
	
	#undef ls
	#undef rs
	
}Ta, Tb;

int main(){
	freopen("girl.in", "r", stdin);
	freopen("girl.out", "w", stdout);
	n = in; m = in;
	for(int i = 1; i <= n; i++) Ta.a[i] = in;
	for(int i = 1; i <= n; i++) Tb.a[i] = in;
	Ta.build(1, 1, n); Tb.build(1, 1, n);
	for(int i = 1; i <= m; i++){
		char op = getchar();
		int l = in; int r = in; int x = in;
		if(op == 'A') Ta.update(1, l, r, x);
		if(op == 'B') Tb.update(1, l, r, x);
		l = in; r = in; int L = l; int R = r;
		int mid = 0;
		int ans = INFI;
		int mxa = 0; int mxb = 0;
		while(l <= r){
			mid = (l + r) >> 1;
			mxa = Ta.query(1, L, mid);
			mxb = Tb.query(1, mid + 1, R);
			ans = min(ans, max(mxa, mxb));
			if(mxa >= mxb) r = mid - 1;
			else l = mid + 1;
		}
		ans = min(ans, Tb.query(1, L, R));
		cout << ans << endl;
	}
	return 0;