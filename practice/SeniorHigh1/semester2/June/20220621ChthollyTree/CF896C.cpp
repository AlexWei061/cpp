#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read() 
#define MAXN 100100
#define MOD 1000000007

struct Tnode{
	
	int l, r;
	mutable int v;
	
	Tnode(int l, int r = 0, int v = 0) : l(l), r(r), v(v) {}
	
	bool operator < (const Tnode &rhs) const { return l < rhs.l; }
	
};

int n = 0; int m = 0;
int seed = 0; int vmax = 0;
int a[MAXN] = { 0 };

set<Tnode> s;

set<Tnode> :: iterator split(int pos){
	set<Tnode> :: iterator it = s.lower_bound(Tnode(pos));
	if(it != s.end() and it -> l == pos) return it;
	it--;
	if(it -> r < pos) return s.end();
	int l = it -> l, r = it -> r, v = it -> v;
	s.erase(it);
	s.insert(Tnode(l, pos - 1, v));
	return s.insert(Tnode(pos, r, v)).first;
}

void add(int l, int r, int x) {
    set<Tnode>::iterator ir = split(r + 1), il = split(l);
    for (set<Tnode>::iterator it = il; it != ir; ++it) it->v += x;
}

void assign(int l, int r, int x){
	set<Tnode> :: iterator ir = split(r + 1), il = split(l);
	s.erase(il, ir);
	s.insert(Tnode(l, r, x));
}

struct Trank{
	
	int num, cnt;
	
	bool operator < (const Trank & rhs) const { return num < rhs.num; }
	
	Trank(int num, int cnt) : num(num), cnt(cnt) {}
	
};

int rk(int l, int r, int x){
	set<Tnode> :: iterator ir = split(r + 1), il = split(l);
	vector<Trank> v;
	for(set<Tnode> :: iterator i = il; i != ir; i++)
		v.push_back(Trank(i -> v, i -> r - i -> l + 1));
	sort(v.begin(), v.end());
	int i = 0;
	for(i = 0; i < v.size(); i++)
		if(v[i].cnt < x) x -= v[i].cnt;
		else break;
	return v[i].num;
}

int power(int x, int y, int p){
	int r = 1, base = x % p;
	while(y){
		if(y & 1) r = r * base % p;
		base = base * base % p;
		y >>= 1;
	}
	return r;
}

int calp(int l, int r, int x, int y){
	set<Tnode> :: iterator ir = split(r + 1), il = split(l);
	int ans = 0;
	for(set<Tnode> :: iterator i = il; i != ir; i++)
		ans = (ans + power(i -> v, x, y) * (i -> r - i -> l + 1) % y) % y;
	return ans; 
}

int rd(){
	int res = seed;
	seed = (seed * 7 + 13) % MOD;
	return res;
}

signed main(){
	cin >> n >> m >> seed >> vmax;
	for(int i = 1; i <= n; i++){
		a[i] = (rd() % vmax) + 1;
		s.insert(Tnode(i, i, a[i]));
	}
	for(int i = 1; i <= m; i++){
		int op = (rd() % 4) + 1;
		int  l = (rd() % n) + 1;
		int  r = (rd() % n) + 1;
		if(l > r) swap(l, r);
		if(op == 1){
			int x = (rd() % vmax) + 1;
			add(l, r, x);
		}
		else if(op == 2){
			int x = (rd() % vmax) + 1;
			assign(l, r, x);
		}
		else if(op == 3){
			int x = (rd() % (r - l + 1)) + 1;
			cout << rk(l, r, x) << '\n';
		}
		else{
			int x = (rd() % vmax) + 1;
			int y = (rd() % vmax) + 1;
			cout << calp(l, r, x, y) << '\n';
		}
	}
	return 0;
}