#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM MAXN << 2

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int ans = 0;
int n = 0; int m = 0;
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int num = 0;
int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
int top = 0;
int stk[MAXN] = { 0 };
int ins[MAXN] = { 0 };
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	stk[++top] = x; ins[x] = 1;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x]){
		int y = 0, cnt = 0;
		do y = stk[top--], ins[y] = 0, cnt++;
		while(x != y);
		if(cnt >= 2) ans++;
	}
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in, y = in;
		add(x, y);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	cout << ans << '\n';
	return 0;
}