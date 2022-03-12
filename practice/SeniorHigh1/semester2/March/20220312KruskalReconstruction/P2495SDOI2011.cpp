#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 500100
#define MAXM 4 * MAXN
#define INF 0x7f7f7f7f7f7f7f7f

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
} 

int n = 0; int m = 0;
int key[MAXN] = { 0 };
int node[MAXN] = { 0 };
int top = 0;
int stk[MAXN] = { 0 };

struct Ttable{
	
	int tot = 0;
	int first[MAXN] = { 0 };
	int   nxt[MAXM] = { 0 };
	int    to[MAXM] = { 0 };
	int value[MAXM] = { 0 };

	inline void clear() { tot = 0; }
	inline void add(int x, int y, int weight){
		nxt[++tot] = first[x];
		first[x] = tot; to[tot] = y;
		value[tot] = weight;
	}
	
}Torigin, Tvirtual;

int num = 0;
int minv[MAXN] = { 0 };
int dfn[MAXN] = { 0 };
int dep[MAXN] = { 0 };
int f[MAXN][25] = { 0 };

void prework(int u, int fa){
	dfn[u] = ++num; dep[u] = dep[fa] + 1;
	for(int i = 0; i <= 20; i++) f[u][i + 1] = f[f[u][i]][i];
	for(int e = Torigin.first[u]; e; e = Torigin.nxt[e]){
		int v = Torigin.to[e];
		if(v != fa){
			f[v][0] = u; minv[v] = min(minv[u], Torigin.value[e]);
			prework(v, u);
		}
	}
}
inline bool comp(int x, int y){ return dfn[x] < dfn[y]; }

int queryLCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}

bool query[MAXN] = { 0 };
int dp(int x){
	int sum = 0;
	int temp = 0;
	for(int e = Tvirtual.first[x]; e; e = Tvirtual.nxt[e]){
		int y = Tvirtual.to[e]; sum += dp(y);
	}
	if(query[x]) temp = minv[x];
	else temp = min(minv[x], sum);
	query[x] = false; Tvirtual.first[x] = 0;
	return temp;
}

signed main(){
	n = in;
	for(int i = 1; i < n; i++){
		int u = in; int v = in; int w = in;
		Torigin.add(u, v, w); Torigin.add(v, u, w);
	}
	minv[1] = INF; prework(1, 0);
	m = in;
	while(m--){
		int k = in;
		for(int i = 1; i <= k; i++) key[i] = in, query[key[i]] = 1;
		sort(key + 1, key + k + 1, comp);
		stk[top = 1] = key[1];
		for(int i = 2; i <= k; i++){
			int lca = queryLCA(key[i], stk[top]);
			while(1)
				if(dep[lca] > dep[stk[top - 1]]){
					if(lca != stk[top]){
						Tvirtual.add(lca, stk[top], 0);
						if(lca != stk[top - 1]) stk[top] = lca;
						else top--;
					}
					break;
				}
				else Tvirtual.add(stk[top - 1], stk[top], 0), top--;
			stk[++top] = key[i];
		}
		while(--top) Tvirtual.add(stk[top], stk[top + 1], 0);
		cout << dp(stk[1]) << '\n'; Tvirtual.clear();
	}
	return 0;
}