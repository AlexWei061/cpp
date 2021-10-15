#include<bits/stdc++.h>
using namespace std;

#define MAXN 200200
#define MAXM 5050

int n = 0; int m = 0;
int a[MAXN] = { 0 };
struct Tnode{
	int l; int r;
	int val;
}t[4 * MAXN];

inline int ls(int p){
	return p << 1;
}
inline int rs(int p){
	return p << 1 | 1;
}

inline void pushup(int p){
	t[p].val = max(t[ls(p)].val, t[rs(p)].val);
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
} 

void update(int p, int index, int val){
	if(t[p].l == t[p].r){
		t[p].val = max(t[p].val, val);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if(index <= mid)
		update(ls(p), index, val);
	else
		update(rs(p), index, val);
	pushup(p); 
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r){
		return t[p].val;
	}
	int ans = -(1 << 30);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid)
		ans = max(ans, query(ls(p), l, r));
	if(r > mid)
		ans = max(ans, query(rs(p), l, r));
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	build(1, 1, n);
	
	for(int i = 1; i <= m; i++){
		scanf("\n");
		char op; int x, y;
		scanf("%c%d%d", &op, &x, &y);
		if(op == 'Q'){
			printf("%d\n", query(1, x, y));
		}
		else{
			update(1, x, y);
		}
	}
	
	return 0;
}
