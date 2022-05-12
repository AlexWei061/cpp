#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define INFI 1 << 30

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-')f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int a[MAXN] =  { 0 };
int n = 0; int m = 0;

struct Tnode{
	int l, r;
	int dat;
	int mx, mxl, mxr;
}t[MAXN * 4];

inline void up(Tnode &p, const Tnode &ls, const Tnode &rs){
	p.mx = max(ls.mx, max(ls.mxr + rs.mxl, rs.mx));
	p.mxl = max(ls.mxl, ls.dat + rs.mxl);
	p.mxr = max(rs.mxr, rs.dat + ls.mxr);
	p.dat = ls.dat + rs.dat;
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r; //t[p].mx = t[p].mxl = t[p].mxr = -INFI;
	if(l == r) { t[p].dat = t[p].mx = t[p].mxl = t[p].mxr = a[l]; return; }
	int mid = (l + r) >> 1;
	build(ls(p), l, mid); build(rs(p), mid + 1, r);
	up(t[p], t[ls(p)], t[rs(p)]);
}

void update(int p, int index, int val){
	if(t[p].l == t[p].r) { t[p].dat = t[p].mx = t[p].mxl = t[p].mxr = val; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if(index <= mid) update(ls(p), index, val);
	else update(rs(p), index, val);
	up(t[p], t[ls(p)], t[rs(p)]);
}

Tnode query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p];
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid and mid < r){
		Tnode res;
	  	up(res, query(ls(p), l, r), query(rs(p), l, r));
	  	return res;
	}
	else if(l <= mid) return query(ls(p), l, r);
	else return query(rs(p), l, r);
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	build(1, 1, n);
	while(m--){
		int op = in;
		if(op == 1){
			int l = in; int r = in;
			if(l > r) swap(l, r);
			cout << query(1, l, r).mx << '\n';
		}
		else{
			int p = in; int s = in;
			update(1, p, s);
		}
	}
	return 0;
}