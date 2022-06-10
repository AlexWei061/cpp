#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 5001000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int tot = 0;
int n = 0; int m = 0;
struct Tedge{
	int val;
	int x, y;
	bool operator < (const Tedge &rhs) const { return val < rhs.val; }
}edges[MAXN];

int fa[MAXN] = { 0 };
inline void init() { for(int i = 1; i <= tot; i++) fa[i] = i; }
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int kruskal(){
	int ans = 0;
	sort(edges + 1, edges + tot + 1);
	for(int i = 1; i <= tot; i++){
		int x = edges[i].x, y = edges[i].y, val = edges[i].val;
		int fax = find(x), fay = find(y);
		if(fax == fay) continue;
		ans += val; fa[fax] = fay;
	}
	return ans;
}

int main(){
	m = in; n = in;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int x = in;
			if(x) edges[++tot].x = i, edges[tot].y = j, edges[tot].val = x;
			if(i != j and !x) edges[++tot].x = i, edges[tot].y = j, edges[tot].val = m;
		}
	for(int i = 1; i <= n; i++) edges[++tot].x = n + 1, edges[tot].y = i, edges[tot].val = m;
	init();
	int ans = kruskal();
	cout << ans << '\n';
	return 0;
}