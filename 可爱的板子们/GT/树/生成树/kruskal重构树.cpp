#include<bits/stdc++.h>
using namespace std;
#define in read()
#define INFI (int)1e9 + (int)1e5
#define MAXN 100100
#define MAXM 100100 * 2
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]

// 给定 n 个点 m 条边的无向图，每条边有一个边权为d_i 。
// 现在有 k 个询问，每次查询两点 x,y 之间的所有路径中，最长的边的最小值是多少。

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int cnt = 0;
int n = 0; int m = 0; int k = 0;
struct Tedge{
	int x, y, w;
	bool operator < (const Tedge &rhs) const {
		return w < rhs.w;
	}
}edge[MAXM]; int tot = 0;
inline void add(int x, int y, int w) { edge[++tot] = (Tedge){x, y, w}; }

int fa[MAXN] = { 0 };
void init1(){
	for(int i = 0; i <= n << 1; i++) fa[i] = i;
}
int find(int x){
	if(fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}

int val[MAXM] = { 0 };
int f[MAXN][21] = { 0 };
int ch[MAXN][2] = { 0 };
void kruskal(){
	sort(edge + 1, edge + tot + 1);
	for(int i = 1; i <= m; i++){
		int x = edge[i].x; int y = edge[i].y;
		int fax = find(x); int fay = find(y);
		if(fax == fay) continue;
		ls(++cnt) = fax; rs(cnt) = fay;
		fa[fa[x]] = fa[fa[y]] = f[fa[x]][0] = f[fa[y]][0] = cnt;
		val[cnt] = edge[i].w;
	}
}

void init2(){
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 2 * n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
}

int dep[MAXN] = { 0 };
void prework(int x){
	if(!ls(x) and !rs(x)) return;
	dep[ls(x)] = dep[rs(x)] = dep[x] + 1;
	prework(ls(x)); prework(rs(x));
}

int queryLCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int main(){
	cnt = n = in; m = in; k = in;
	for(int i = 1; i <= m; i++){
		int x = in; int y = in; int w = in; add(x, y, w);
	}
	init1(); kruskal();
	dep[cnt] = 1; prework(cnt);
	init2();
	while(k--){
		int x = in; int y = in;
		cout << val[queryLCA(x, y)] << '\n';
	}
	return 0;
}
