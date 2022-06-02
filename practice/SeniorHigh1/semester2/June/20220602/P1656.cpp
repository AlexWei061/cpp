#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010
#define MAXM 10100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

struct Tedge{
	int x, y;
	bool operator < (const Tedge &rhs) const {
		return x == rhs.x ? (y < rhs.y) : (x < rhs.x);
	}
}edges[MAXM];

int num = 0, cnt = 0;
int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
void tarjan(int x, int edge){
	dfn[x] = low[x] = ++num;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y, e);
			low[x] = min(low[x], low[y]);
			if(dfn[x] < low[y]) edges[++cnt].x = x, edges[cnt].y = y;
		}
		else if(e != (edge ^ 1)) low[x] = min(low[x], dfn[y]);
	}
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in, y = in;
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
	sort(edges + 1, edges + cnt + 1);
	for(int i = 1; i <= cnt; i++) cout << edges[i].x << ' ' << edges[i].y << '\n';
	return 0;
}