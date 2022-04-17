#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 100100
#define MOD 100000000 - 3

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int q[MAXN] = { 0 };
int ida[MAXN] = { 0 };
int idb[MAXN] = { 0 };
int t[MAXN * 4] = { 0 };
bool compa(int x, int y) { return a[x] < a[y]; }
bool compb(int x, int y) { return b[x] < b[y]; }

inline int lowbit(int x) { return x & -x; }
void add(int x, int y){
	for(; x <= n; x += lowbit(x)) t[x] = t[x] + y, t[x] %= MOD;
}
int query(int x){
	int ans = 0;
	for(; x >= 1; x -= lowbit(x)) ans = ans + t[x], ans %= MOD;
	return ans;
}

signed main(){
	n = in; int ans = 0;
	for(int i = 1; i <= n; i++) a[i] = in, ida[i] = i;
	for(int i = 1; i <= n; i++) b[i] = in, idb[i] = i;
	sort(ida + 1, ida + n + 1, compa);
	sort(idb + 1, idb + n + 1, compb);
	for(int i = 1; i <= n; i++) q[ida[i]] = idb[i];
	for(int i = n; i >= 1; i--)
		add(q[i], 1), ans = ans + query(q[i] - 1), ans %= MOD;
	cout << ans << '\n';
	return 0;
}