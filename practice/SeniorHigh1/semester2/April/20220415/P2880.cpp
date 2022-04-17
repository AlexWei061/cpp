#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001000
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int m = 0;

struct Tnode{
	int l, r;
	int dat;
}t1[MAXN * 4], t2[MAXN * 4];

inline void up1(int p) { t1[p].dat = max(t1[ls(p)].dat, t1[rs(p)].dat); }
void build1(int p, int l, int r){
	t1[p].l = l; t1[p].r = r;
	if(l == r) { t1[p].dat = a[l]; return; }
	int mid = (l + r) >> 1;
	build1(ls(p), l, mid);
	build1(rs(p), mid + 1, r);
	up1(p);
}

int query1(int p, int l, int r){
	if(l <= t1[p].l and t1[p].r <= r) return t1[p].dat;
	int mid = (t1[p].l + t1[p].r) >> 1; int ans = -INFI;
	if(l <= mid) ans = max(ans, query1(ls(p), l, r));
	if(r >  mid) ans = max(ans, query1(rs(p), l, r));
	return ans;
}

inline void up2(int p) { t2[p].dat = min(t2[ls(p)].dat, t2[rs(p)].dat); }
void build2(int p, int l, int r){
	t2[p].l = l; t2[p].r = r;
	if(l == r) { t2[p].dat = a[l]; return; }
	int mid = (l + r) >> 1;
	build2(ls(p), l, mid);
	build2(rs(p), mid + 1, r);
	up2(p);
}

int query2(int p, int l, int r){
	if(l <= t2[p].l and t2[p].r <= r) return t2[p].dat;
	int mid = (t2[p].l + t2[p].r) >> 1; int ans = INFI;
	if(l <= mid) ans = min(ans, query2(ls(p), l, r));
	if(r >  mid) ans = min(ans, query2(rs(p), l, r));
	return ans;
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	build1(1, 1, n); build2(1, 1, n);
	while(m--){
		int l = in; int r = in;
		int mx = query1(1, l, r);
		int mn = query2(1, l, r);
		cout << mx - mn << '\n';
	}
	return 0;
}