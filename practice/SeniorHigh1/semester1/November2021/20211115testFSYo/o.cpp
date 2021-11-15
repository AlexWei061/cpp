#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 50500 
#define ls(p) (p << 1)
#define rs(P) (p << 1 | 1)
#define in read()
#define endl '\n'

inline int read(){
	int x = 0; char c = getchar();
	while(c > '9' or c < '0') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int q = 0;

struct Tnode{
	int l, r;
	int dat;
}t[4 * MAXN];
inline void pushup(int p){
	t[p].dat = t[ls(p)].dat + t[rs(p)].dat;
}

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = a[l]; return;
	}
	int mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

void update(int p, int index, int val){
	if(t[p].l == t[p].r){
		t[p].dat = val; return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if(index <= mid) update(ls(p), index, val);
	else update(rs(p), index, val);
	pushup(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	int mid = (t[p].l + t[p].r) >> 1; int ans = 0;
	if(l <= mid) ans += query(ls(p), l, r);
	if(r > mid)  ans += query(rs(p), l, r);
	return ans;
}

struct Tqu{
	int t;
	int idx;
	int ans;
	int l, r;
}qu[MAXN];
bool comp1(Tqu a, Tqu b){
	return a.t < b.t;
}
bool comp2(Tqu a, Tqu b){
	return a.idx < b.idx;
}

signed main(){
	n = in; q = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		qu[i].t = in; qu[i].l = in; qu[i].r = in; qu[i].idx = i;
	} sort(qu+1, qu+q+1, comp1);
	int idx = 1;
	for(int i = 1; i <= qu[q].t; i++){
		for(int j = 1; j <= n; j++) update(1, j, max(a[j], a[j-1]));
		for(int j = 1; j <= n; j++) a[j] = query(1, j, j);
		while(qu[idx].t == i){
			qu[idx].ans = query(1, qu[idx].l, qu[idx].r);
			idx++;
		}
	} sort(qu+1, qu+q+1, comp2);
	for(int i = 1; i <= n; i++)  cout << qu[i].ans << endl;
	return 0;
}