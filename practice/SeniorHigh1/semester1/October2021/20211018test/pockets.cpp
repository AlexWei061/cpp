#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in read()
#define MAXN 500500

int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int q = 0; int P = 0;
int a[MAXN] = { 0 };

struct SegTree{
	int l; int r;
	ll dat; int lazy;
}t[4 * MAXN];

int ls(int p){
	return p << 1;
}
int rs(int p){
	return p << 1 | 1;
}

void pushup(int p){
	t[p].dat = t[ls(p)].dat + t[rs(p)].dat;
}

void pushdown(int p){
	t[ls(p)].dat += (ll)t[p].lazy * (ll)(t[ls(p)].r - t[ls(p)].l + 1);                  
	t[rs(p)].dat += (ll)t[p].lazy * (ll)(t[rs(p)].r - t[rs(p)].l + 1);
	t[ls(p)].lazy += t[p].lazy; t[rs(p)].lazy += t[p].lazy;
	t[p].lazy = 0;
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = a[l] % P; return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

void update(int p, int l, int r, int val){
	if(l <= t[p].l and t[p].r <= r){
		t[p].dat += (ll)(t[p].r - t[p].l + 1) * (ll)val;
		t[p].lazy += val; return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) update(ls(p), l, r, val);
	if(r > mid)  update(rs(p), l, r, val);
	pushup(p);
}

ll query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r)
		return t[p].dat;
	pushdown(p);
	ll ans = 0;
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) ans += query(ls(p), l, r);
	if(r > mid)  ans += query(rs(p), l, r);
	return ans;
}

int main(){
	freopen("pockets.in", "r", stdin);
	freopen("pockets.out", "w", stdout);
	n = in; q = in; P = in;
	for(int i = 1; i <= n; i++){
		a[i] = in;
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		int op = in; int l = in;  int r = in; int k = in;
		if(op == 1){
			update(1, l, r, k);
		}
		else if(op == 2){
			bool is = true;
			while(k--){
				if((query(1, l, l) % P) != (query(1, r, r) % P)){
					is = false; break;
				}
				l++; r++;
			}
			if(is) printf("ye5\n");
			else   printf("n0\n");
		}
	}
	return 0;
}