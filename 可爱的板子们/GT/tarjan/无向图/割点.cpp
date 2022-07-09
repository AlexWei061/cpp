#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 4 * MAXN

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int dfn[MAXN] = { 0 };
int low[MAXN] = { 0 };
int cut[MAXN] = { 0 };
int num = 0, cnt = 0, root = 0;
void tarjan(int x){
	dfn[x] = low[x] = ++num; int temp = 0;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if(dfn[x] <= low[y]){
				temp++;
				if(x != root or temp > 1) cut[++cnt] = x;
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in, y = in;
		if(x == y) continue;
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) root = i, tarjan(i);
	sort(cut + 1, cut + cnt + 1);
	cnt = unique(cut + 1, cut + cnt + 1) - cut - 1;
	cout << cnt << '\n';
	for(int i = 1; i <= cnt; i++) cout << cut[i] << ' '; puts("");
	return 0;
}
