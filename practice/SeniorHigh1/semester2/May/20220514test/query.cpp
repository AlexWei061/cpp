#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200	

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int q = 0;
int c[MAXN * 4] = { 0 };

struct Tq{
	int l, r, x;
	int ans, idx;
}qs[MAXN];
bool comp1(Tq a, Tq b) { return a.l < b.l; }
bool comp2(Tq a, Tq b) { return a.r < b.r; }
bool comp3(Tq a, Tq b) { return a.idx < b.idx; }

inline int lowbit(int x) { return x & -x; }
void add(int x){
	for(; x <= n; x += lowbit(x)) c[x]++;
}
int query(int x){
	int ans = 0;
	for(; x; x -= lowbit(x)) ans += c[x];
	return ans; 
}

int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	n = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	q = in;
	for(int i = 1; i <= q; i++)
		qs[i].l = in, qs[i].r =in, qs[i].x = in, qs[i].idx = i;
	int j = 1; sort(qs + 1, qs + q + 1, comp1);
	for(int i = 1; i <= n; i++){
		add(a[i]);
		while(qs[j].l < i + 1 and j <= q) j++;
		while(qs[j].l == i + 1 and j <= q){
			int a = query(qs[j].x) - query(qs[j].x - 1);
			qs[j].ans -= a; j++;
		}
	} memset(c, 0, sizeof(c));
	j = 1; sort(qs + 1, qs + q + 1, comp2);
	for(int i = 1; i <= n; i++){
		add(a[i]);
		while(qs[j].r < i and j <= q) j++;
		while(qs[j].r == i and j <= q){
			int a = query(qs[j].x) - query(qs[j].x - 1);
			qs[j].ans += a; j++;
		}
	}
	sort(qs + 1, qs + q + 1, comp3);
	for(int i = 1; i <= q; i++) cout << qs[i].ans << '\n';
	return 0;
}