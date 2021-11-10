#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second 
#define in read()
#define MAXN 500500
typedef pair<int, int> pii;

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int q = 0;
int n = 0; int m = 0;
int pre[MAXN] = { 0 };
int fa[MAXN] = { 0 };
int c[MAXN] = { 0 };
int d[MAXN] = { 0 };
int l[MAXN] = { 0 };
pii b[MAXN];
set<int> co[MAXN];
set<pair<pii, int> > s;

struct Tnode{
	int l, r;
	int dat;
}t[4 * MAXN];
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
inline void pushup(int p){
	t[p].dat = max(t[ls(p)].dat, t[rs(p)].dat);
}
void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){
		t[p].dat = pre[l];
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
	if(index <= mid) update(ls(p), index, val);
	else update(rs(p), index, val);
	pushup(p);
}
int query(int p, int l, int r){
	if(l <= t[p].l and t[p].r <= r) return t[p].dat;
	int mid = (t[p].l + t[p].r) >> 1; int ans = -1;
	if(l <= mid) ans = max(ans, query(ls(p), l, r));
	if(r > mid)  ans = max(ans, query(rs(p), l, r));
	return ans;
}

inline bool isin(pii x, pii y){
	return y.fi <= x.fi and x.se <= y.se;
}
inline bool comp(pair<pii, int> x, pair<pii, int> y){
	return x.fi.fi == y.fi.fi ? x.fi.se > y.fi.se : x.fi.fi < y.fi.fi;
}
void init(){
	for(int i = 1; i <= n; i++) co[i].insert(0);
	for(int i = 1; i <= n; i++){
		pre[i] = *(co[c[i]].rbegin());
		co[c[i]].insert(i);
	}
	build(1, 1, n);
	pair<pii, int> temp[MAXN];
	b[0].fi = -1; b[0].se = n + 1;
	for(int i = 0; i <= m; i++){
		temp[i].fi = b[i]; temp[i].se = i;
	}
	sort(temp, temp + m + 1, comp);
	stack<int> stk; stk.push(0);
	for(int i = 1; i <= m; i++){
		while(!isin(temp[i].fi, temp[stk.top()].fi)) stk.pop();
		fa[temp[i].se] = temp[stk.top()].se; d[fa[temp[i].se]]++;
		stk.push(i);
	}
	for(int i = 1; i <= m; i++){
		if(!d[i]) s.insert({b[i], i});
	}
}

void modify(int x, int d){
	auto p = co[c[x]].lower_bound(x);
	auto bf = p; auto nx = p; nx++; bf--;
	if(nx != co[c[x]].end()) update(1, *nx, *bf);
	co[c[x]].erase(x);
	c[x] = d;
	nx = co[c[x]].lower_bound(x);
	bf = nx; bf--; update(1, x, *bf);
	if(nx != co[c[x]].end()) update(1, *nx, x);
	co[c[x]].insert(x);
}

int queryB(int x){
	auto p = s.upper_bound({{x, n + 1}, m + 1});
	if(p == s.begin()) return -1;
	p--; auto B = *p;
	if(B.fi.fi <= x and x <= B.fi.se) return B.se;
	return -1;
}

void check(int id, int i){
	if(id <= 0) return;
	if(query(1, b[id].fi, b[id].se) >= b[id].fi) return;
	l[id] = i; s.erase({b[id], id});
	if(!(--d[fa[id]])){
		s.insert({b[fa[id]], fa[id]}); check(fa[id], i);
	}
}

int main(){
	n = in; m = in; q = in;
	for(int i = 1; i <= n; i++) c[i] = in;
	for(int i = 1; i <= m; i++){
		b[i].fi = in; b[i].se = in; l[i] = -1;
	}
	init();
	vector<int> leaf;
	for(auto v : s) leaf.push_back(v.se);
	for(int v : leaf) check(v, 0);
	for(int i = 1; i <= q; i++){
		int x = in; int y = in;
		modify(x, y); check(queryB(x), i);
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(l[i] == -1) ans ^= m + i;
		else ans ^= l[i];
	}
	cout << ans << endl;
	return 0;
}