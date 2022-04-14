#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 5050
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

int n = 0;
int cnt[MAXN * 4] = { 0 };
int sum[MAXN * 4] = { 0 };
int all[MAXN * 2] = { 0 };

struct Tnode{
	int l, r, h; int d;
	Tnode() {}
	Tnode(int l, int r, int h, int d): l(l), r(r), h(h), d(d) {};
	bool operator < (const Tnode &rhs) const { return h < rhs.h; } 
}a[MAXN];

void pushup(int l, int r, int rt){
	if(cnt[rt]) sum[rt] = all[r + 1] - all[l];
	else if(l == r) sum[rt] = 0;
	else sum[rt] = sum[ls(rt)] + sum[rs(rt)];
}

void update(int L, int R, int d, int l, int r, int rt){
	if(L <= l and r <= R){
		cnt[rt] += d;
		pushup(l, r, rt);
		return;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) update(L, R, d, l, mid, ls(rt));
	if(R > mid) update(L, R, d, mid + 1, r, rs(rt));
	pushup(l, r, rt);
}

signed main(){
	n = in; int ans = 0;
	for(int i = 1; i <= n; i++){
		int x1 = in; int y1 = in;
		int x2 = in; int y2 = in;
		a[i] = Tnode(x1, x2, y1, 1);
		a[i + n] = Tnode(x1, x2, y2, -1);
		all[i] = x1; all[i + n] = x2;
	}
	n <<= 1;
	sort(a + 1, a + n + 1); sort(all + 1, all + n + 1);
	int k = unique(all + 1, all + n + 1) - all - 1;
	for(int i = 1; i < n; i++){
		int l = lower_bound(all + 1, all + k + 1, a[i].l) - all;
		int r = lower_bound(all + 1, all + k + 1, a[i].r) - all;
		if(l < r) update(l, r - 1, a[i].d, 1, k, 1);
		ans += sum[1] * (a[i + 1].h - a[i].h);
	}
	cout << ans << '\n';
	return 0;
}