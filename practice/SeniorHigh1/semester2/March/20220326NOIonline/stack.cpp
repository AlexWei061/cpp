#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int q = 0;
int top = 0;
int stk[MAXN] = { 0 };
struct Tnode{
	int a; int b;
	bool operator < (const Tnode &x) const { return (a != x.a) and (b < x.b); }       // 能入栈的条件 
	bool operator >= (const Tnode &x) const { return !((*this) < x); }                // 能入栈的条件取反 
	bool operator == (const Tnode &x) const { return a == x.a; }
}arr[MAXN];

struct BIT{
	int t[MAXN << 2];
	
	inline int lowbit(int x) { return x & -x; }
	void clear() { memset(t, 0, sizeof(t)); }
	void add(int x, int val){
		for(; x <= n; x += lowbit(x)) t[x] += val;
	}
	int query(int x){
		int ans = 0;
		for(; x; x -= lowbit(x)) ans += t[x];
		return ans;
	}
}T;

struct Tq{
	int l; int r;	
}que[MAXN];
int p[MAXN] = { 0 };
int b[MAXN] = { 0 };           // 处理左端点时 b[i] = h[que[i].l]
int h[MAXN] = { 0 };           // 处理左端点时 h[que[i].l] = i
int ans[MAXN] = { 0 };
void solve(){
	stk[++top] = 1; p[1] = 1; T.add(1, 1); 
	for(int i = 2; i <= n; i++){
		while(stk[top] and (arr[i] >= arr[stk[top]])) top--;
		p[i] = stk[top] + 1; stk[++top] = i;
	}
	for(int i = 1; i <= q; i++) { que[i].l = in; que[i].r = in; }            // 把询问离线下来 
	for(int i = 1; i <= q; i++) b[i] = h[que[i].l], h[que[i].l] = i;
	for(int i = 1; i <= n; i++){
		for(int j = h[i]; j; j = b[j]) ans[j] -= T.query(que[j].l);
		T.add(p[i], 1);
	}
	T.clear(); memset(h, 0, sizeof(h));
	for(int i = 1; i <= q; i++) b[i] = h[que[i].r], h[que[i].r] = i;
	for(int i = 1; i <= n; i++){
		T.add(p[i], 1);
		for(int j = h[i]; j; j = b[j]) ans[j] += T.query(que[j].l);
	}
	for(int i = 1; i <= q; i++) cout << ans[i] + 1 << '\n';
}

int main(){
	n = in;  q = in;
	for(int i = 1; i <= n; i++) arr[i].a = in;
	for(int i = 1; i <= n; i++) arr[i].b = in;
	solve();
	return 0;
}