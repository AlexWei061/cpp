#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int b[MAXN] = { 0 };
int a[MAXN] = { 0 };
int n = 0; int m = 0;

struct Tnode{
	int dat;
	int ls, rs;
}t[MAXN * 32];
int tot = 0;
int root[MAXN];

inline void up(int p) { t[p].dat = t[t[p].ls].dat + t[t[p].rs].dat; }

int build(int l, int r){
	int p = ++tot;
	if(l == r) return p;
	int mid = (l + r) >> 1;
	t[p].ls = build(l, mid);
	t[p].rs = build(mid + 1, r);
	up(p); return p;
}

int update(int now, int l, int r, int x, int val){
	int p = ++tot; t[p]= t[now];
	if(l == r) { t[p].dat += val; return p; }
	int mid = (l + r) >> 1;
	if(x <= mid) t[p].ls = update(t[now].ls, l, mid, x, val);
	else t[p].rs = update(t[now].rs, mid + 1, r, x, val);
	up(p); return p;
}

int query(int p, int q, int l, int r, int k){
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int lcnt = t[t[p].ls].dat - t[t[q].ls].dat;
	if(k <= lcnt) return query(t[p].ls, t[q].ls, l, mid, k);
	else return query(t[p].rs, t[q].rs, mid + 1, r, k - lcnt);
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) a[i] = b[i] = in;
	sort(b + 1, b + n + 1); int q = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++){
		int p = lower_bound(b + 1, b + q + 1, a[i]) - b;
		root[i] = update(root[i - 1], 1, n, p, 1);
	}
	while(m--){
		int l = in; int r = in; int k = in;
		cout << b[query(root[r], root[l - 1], 1, n, k)] << '\n';
	}
	return 0;
}
