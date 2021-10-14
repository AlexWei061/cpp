#include<bits/stdc++.h>
using namespace std;

#define MAXN 400400

int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') { c = getchar(); }
	while('0' < c and c < '9') { x = x * 10 + (c - '0'), c = getchar(); }
	return x;
}

int n = 0; int m = 0;
int a[MAXN] = { 0 };
struct SegTree{
	int l, r;
	int dat;
}t[4 * MAXN];

inline int ls(int p){
	return p << 1;
}
inline int rs(int p){
	return p << 1 | 1;
}

inline void pushup(int p){
	t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat);
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

void update(int p, int index, int val){
	if(t[p].l == t[p].r){
		t[p].dat = val;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if(index <= mid){
		update(ls(p), index, val);
	}
	else{
		update(rs(p), index, val);
	}
	pushup(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r){
		return t[p].dat;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = -(1 << 30);
	if(l <= mid){
		ans = max(ans, query(ls(p), l, r));
	}
	if(r > mid){
		ans = max(ans, query(rs(p), l, r));
	}
	return ans;
}

int main(){
	//printf("n = %d m = %d\n", n, m);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	
	for(int i = 1; i <= m; i++){
		//printf("i = %d\n", i);
		char op; int x, y;
		scanf("\n");
		scanf("%c%d%d", &op, &x, &y);
		if(op == 'Q'){
			printf("%d\n", query(1, x, y));
		}
		else if(op == 'U'){
			update(1, x, y);
		}
	}
	return 0;
}
