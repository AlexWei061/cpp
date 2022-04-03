#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 500500
#define MAXM MAXN * 8

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x ;
}

int n = 0; int m = 0;
int cnt = 0; int ans = 0;
struct Tedge{
	int x, y;
	int val;
	bool operator < (const Tedge &rhs) const {
		return val < rhs.val;
	}
}edge[MAXM];

int fa[MAXN] = { 0 };
void init() { for(int i = 0; i <= n; i++) fa[i] = i; }
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

bool isok[MAXN] = { 0 };
void kruskal(){
	for(int i = 1; i <= m; i++){
		int fax = find(edge[i].x); int fay = find(edge[i].y);
		if(fax == fay){
			if(!isok[fax]) { isok[fax] = 1; ans += edge[i].val; cnt++; }
		} else{
			if(isok[fax] and isok[fay]) continue;
			fa[fax] = fay; isok[fay] = isok[fay] | isok[fax];
			ans += edge[i].val; cnt++;
		}
	}
}

signed main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++)
		edge[i].x = in, edge[i].y = in, edge[i].val = in;
	sort(edge + 1, edge + m + 1);
	init(); kruskal();
	if(n != cnt) puts("No");
	else cout << ans << '\n';
	return 0;
}
