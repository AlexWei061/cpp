#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500
#define MAXM 5050

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int q = 0;
struct Tnode{
	int a; int b;
	bool operator < (const Tnode &x) const { return (a != x.a) and (b < x.b); }       // 能入栈的条件 
	bool operator >= (const Tnode &x) const { return !((*this) < x); }                // 能入栈的条件取反 
	bool operator == (const Tnode &x) const { return a == x.a; }
}arr[MAXN];

int ans[MAXM][MAXM] = { 0 };
int top = 0;
int stk[MAXN] = { 0 };
void solve1(){
	for(int i = 1; i <= n; top = 0, i++){
		ans[i][i] = 1; stk[++top] = i;
		for(int j = i + 1; j <= n; j++){
			while(top and arr[j] >= arr[stk[top]]) top--;
			ans[i][j] = ans[i][j - 1] + (top == 0); stk[++top] = j;
		}
	}
	while(q--) { int l = in; int r = in; cout << ans[l][r] << '\n'; }
}

struct BIT{
	
	int f[MAXN];
	vector<int> t[MAXN];

	int lowbit(int x) { return x & -x; }
	
	void add(int x){
		for(int i = x; i <= n; i += lowbit(i))
			t[i].push_back(f[x]);
	}
	
	int query(int c, int x){
		int ans = 0;
		for(int i = x; i; i -= lowbit(i))
			ans += (lower_bound(t[i].begin(), t[i].end(), c + 1) - t[i].begin());
		return ans - c + 1;
	}
	
}T;

void solve2(){
	for(int i = 1; i <= n; i++){
		T.f[i] = i;
		while(T.f[i] >= 2 and (arr[i].b >= arr[T.f[i] - 1].b or arr[i].a == arr[T.f[i] - 1].a)){
			T.f[i] = T.f[T.f[i] - 1];
		}
		T.add(i); sort(T.t[i].begin(), T.t[i].end());
	}
	while(q--){ int l = in; int r = in; cout << (T.query(l, r)) << '\n'; }
}

int main(){
	n = in;  q = in;
	bool flaga = 1; bool flagb = 1;
	for(int i = 1; i <= n; i++) if((arr[i].a = in) != i) flaga = 0;
	for(int i = 1; i <= n; i++) if((arr[i].b = in) != (n - i + 1)) flagb = 0;
	if(n <= 5000) solve1();
	else solve2();
	return 0;
}