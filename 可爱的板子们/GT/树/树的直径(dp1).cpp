#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500
#define MAXM 4 * MAXN

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

inline void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	value[tot] = weight;
}

int n = 0;
int v[MAXN] = { 0 };
int d[MAXN] = { 0 };
int ans = 0;
void dp(int x){
	v[x] = 1;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(v[y]) continue;
		dp(y);
		ans = max(ans, d[x] + d[y] + value[e]);
		d[x] = max(d[x], d[y] + value[e]);
	}
}

int main(){
	n = in;
	for(int i = 1; i < n; i++){
		int x = in, y = in, w = in;
		add(x, y, w); add(y, x, w);
	}
	dp(1);
	cout << ans << '\n';
	return 0;
}
