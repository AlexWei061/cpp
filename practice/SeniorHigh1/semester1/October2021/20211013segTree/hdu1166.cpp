#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int k = 0;
int n = 0;
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
	t[p].dat = t[ls(p)].dat + t[rs(p)].dat;
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
		t[p].dat += val;
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
	int ans = 0;
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid){
		ans += query(ls(p), l, r);
	}
	if(r > mid){
		ans += query(rs(p), l, r);
	}
	return ans;
}

int main(){
	scanf("%d", &k);
	for(int cas = 1; cas <= k; cas++){
		printf("Case %d:\n", cas);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		build(1, 1, n);
		char op[10];
		while(scanf("%s", op)){
			if(op[0] == 'E'){
				break;
			}
			int x, y;
			scanf("%d%d", &x, &y);
			if(op[0] == 'A'){
				update(1, x, y);
			}
			else if(op[0] == 'S'){
				update(1, x, -y);
			}
			else if(op[0] == 'Q'){
				printf("%d\n", query(1, x, y));
			}
		}
	}
	return 0;
}
