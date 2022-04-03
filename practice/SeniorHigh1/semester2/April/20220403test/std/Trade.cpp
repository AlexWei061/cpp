#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 100100
#define MAXM MAXN * 8

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x ;
}

int ans = 0;
int n = 0; int m = 0;
struct Tedge{
	int x, y;
	int val; bool used;
	bool operator < (const Tedge &rhs) const {
		return val < rhs.val;
	}
}edge[MAXM];

int fa[MAXN] = { 0 };
void init() { for(int i = 1; i <= n; i++) fa[i] = i; }
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void kruskal(){
	for(int i = 1; i <= m; i++){
		Tedge e = edge[i];
		int fax = find(e.x); int fay = find(e.y);
		if(fax == fay) continue;
		fa[fax] = fay; ans += e.val; edge[i].used = 1; 
	}
}

signed main(){
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	n = in; m = in;
	if(m < n) { cout << "No\n"; return 0; }
	for(int i = 1; i <= m; i++){
		edge[i].x = in, edge[i].y = in, edge[i].val = in;
	}
	sort(edge + 1, edge + m + 1);
	init(); kruskal();
	for(int i = 1; i <= n; i++)
		if(!edge[i].used) { ans += edge[i].val; break; }
	cout << ans << '\n';
	return 0;
}
