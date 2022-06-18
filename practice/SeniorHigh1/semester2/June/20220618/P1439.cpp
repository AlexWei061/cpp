#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define ls(p) p << 1
#define rs(p) p << 1 | 1

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int c[MAXN] = { 0 };
int f[MAXN] = { 0 };

struct Tnode{
	int dat;
	int l, r;
}t[MAXN << 10];

inline void up(int p) { t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat); }

void build(int p, int l, int r){
	t[p].l = l, t[p].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
}

void update(int p, int x, int val){
	if(t[p].l == t[p].r) { t[p].dat = val; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if(x <= mid) update(ls(p), x, val);
	else update(rs(p), x, val);
	up(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	int mid = (t[p].l + t[p].r) >> 1; int ans = 0;
	if(l <= mid) ans = max(ans, query(ls(p), l, r));
	if(r > mid)  ans = max(ans, query(rs(p), l, r));
	return ans;
}

int main(){
	n = in; int ans = 0;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) b[i] = in;
	for(int i = 1; i <= n; i++) c[a[i]] = i;
	for(int i = 1; i <= n; i++) b[i] = c[b[i]];
	build(1, 1, n);
	for(int i = 1; i <= n; i++)	{
		f[i] = query(1, 1, b[i] - 1) + 1;
		update(1, b[i], f[i]);
	}
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
}