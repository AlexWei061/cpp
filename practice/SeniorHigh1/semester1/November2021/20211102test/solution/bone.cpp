#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005
#define oo 1231231231231231231

template <typename T> void read(T &x){
	x = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) and c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x;
}

struct Tnode{
	int ls, rs;
	ll x;
};

struct SegTree{
	#define mid ((l + r) >> 1)
	int cnt;
	Tnode t[MAXN * 75];

	void pushup(int node){
		t[node].x = t[t[node].ls].x + t[t[node].rs].x;
	}

	void update(int &a, ll l, ll r, ll p, ll x){
		t[++cnt] = t[a];
		a = cnt;
		if(l == r) t[a].x += x;
		else if(p <= mid) update(t[a].ls, l, mid, p, x), pushup(a);
		else update(t[a].rs, mid+1, r, p, x), pushup(a);
	}

	ll query(int a, ll l, ll r, ll ql, ll qr){
		if(!a) return 0;
		else if(ql <= l and r <= qr) return t[a].x;
		else if(ql > r or qr < l) return 0;
		else return query(t[a].ls, l, mid, ql, qr) + query(t[a].rs, mid+1, r, ql, qr);
	}

	#undef mid
}T;

int n; int m; ll x;
ll a[MAXN] = { 0 };
int root[MAXN] = { 0 };
ll Floor[MAXN] = { 0 };
ll preFl[MAXN] = { 0 };

void input(){
	read(n); read(m); read(x);
	for(int i = 1; i <= n; i++) read(a[i]);
}

void init(){
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) Floor[i] = a[i] / x;
	for(int i = n; i >= 1; i--){
		preFl[i] = preFl[i+1] + Floor[i];
		root[i] = root[i+1];
		T.update(root[i], 0, x, a[i] % x, 1);
	}
}

ll check(ll tar){
	ll ret = 0;
	int p = lower_bound(a + 1, a + n + 1, tar) - a;
	ret = preFl[p] - (tar / x) * (n - p + 1);
	ret += T.query(root[p], 0, x, tar % x + 1, x);
	return ret;
}

ll work(ll t){
	ll l = 0; ll r = a[n];
	ll ans = 0; ll mid = 0;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid) > t) l = ans = mid + 1;
		else r = ans = mid;
	}
	return max(ans - t, 0ll);
}

int main(){
	input(); init();
	for(int i = 1; i <= m; i++){
		ll t;
		read(t);
		printf("%lld\n", work(t));
	}
	return 0;
}
