#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM MAXN * 4
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int n = 0; int q = 0;
int d[MAXN] = { 0 }; int l[MAXN] = { 0 };
stack<int> stk;

int dep[MAXN] = { 0 };
int f[MAXN][30] = { 0 };                          // 存祖先 
int g[MAXN][30] = { 0 };                          // 存路径和 
void prework(int x, int fa){
	dep[x] = dep[fa] + 1; f[x][0] = fa; g[x][0] = value[fa];
	for(int i = 1; (1 << i) <= dep[x]; i++)
		f[x][i] = f[f[x][i - 1]][i - 1], g[x][i] = g[f[x][i - 1]][i - 1] + g[x][i - 1]; 
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e]; prework(y, x);
	}
}

int main(){
	n = in; q = in;
	for(int i = 1; i <= n; i++)
		d[i] = in, value[i] = in;
	d[n + 1] = INFI; value[n + 1] = INFI; stk.push(1);
	for(int i = 2; i <= n + 1; i++){
		while(!stk.empty() and d[i] > d[stk.top()]) l[stk.top()] = i, stk.pop();
		stk.push(i);
	}
	for(int i = 1; i <= n; i++) add(l[i], i); prework(n + 1, 0);                    // n + 1 当做根节点 
	while(q--){
		int x = in; int l = in;
		if(value[x] >= l) { cout << x << '\n'; continue; }
		l -= value[x]; int ans = 0;
		for(int i = 30; i >= 0; i--){
			if(g[x][i] <= l and (1 << i) <= dep[x])
				l -= g[x][i], x = f[x][i];
			if(l == 0) ans = x;
		}
		if(ans == 0) ans = f[x][0];
		if(ans == n + 1) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}