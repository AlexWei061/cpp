#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int a[MAXN] = { 0 };
s
struct SegmentTree{
	int l, r;
	int dat;
}t[MAXN * 4];

inline int ls(int p){
	return p << 1;
}
inline int rs(int p){
	return p << 1 | 1;
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	//printf("l = %d r = %d\n", l, r);
	if(l == r){
		t[p].dat = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid+1, r);
	t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat);
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
	t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat);
}

int query(int p, int l, int r){
	//printf("l = %d r = %d p.l = %d p.r = %d\n", l, r, t[p].l, t[p].r);
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
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	build(1, 1, n);
	
	printf("%d\n", query(1, 3, 5));
	
	return 0;
}
