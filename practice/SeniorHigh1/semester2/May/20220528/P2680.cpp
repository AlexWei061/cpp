#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 300300
#define MAXM 4 * MAXN
#define INFI (int)3e8

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c=  getchar();
	}
	return x;
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

int pre[MAXN] = { 0 };
int dis[MAXN] = { 0 };
int dep[MAXN] = { 0 };
int f[MAXN][32] = { 0 };
void prework(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = 0; i <= 30; i++) f[x][i + 1] = f[f[x][i]][i];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		f[y][0] = x; dis[y] = dis[x] + value[e]; pre[y] = value[e];
		prework(y, x);
	}
}

int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 30; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 30; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}

int n = 0; int m = 0;
struct Tedge{
	int len;
	int x, y, lca;
	bool operator < (const Tedge &rhs) const { return len > rhs.len; }
}edge[MAXM];

int mx = 0; int cnt = 0;
int flag = 0;
int sum[MAXN] = { 0 };

int judge(int x, int fa, int cnt, int mx){
	int num = sum[x];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		num += judge(y, x, cnt, mx);
	}
	if(num >= cnt and pre[x] >= mx) flag = 1;
	return num;
}

int check(int x){
	cnt = mx = flag = 0; memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= m; i++){
		if(edge[i].len > x){
			sum[edge[i].x]++, sum[edge[i].y]++, sum[edge[i].lca] -= 2;
			cnt++; mx = max(mx, edge[i].len);
		}
	}
	if(cnt == 0) return 1;
	int k = judge(1, 0, cnt, mx - x);
	return flag;
}

signed main(){
	n = in; m = in;
	for(int i = 1; i < n; i++){
		int x = in, y = in, w = in;
		add(x, y, w); add(y, x, w);
	} prework(1, 0);
//	for(int i = 1; i <= n; i++) cout << dis[i] << ' '; puts("");
//	for(int i = 1; i <= n; i++) cout << pre[i] << ' '; puts("");
	for(int i = 1; i <= m; i++){
		edge[i].x = in; edge[i].y = in;
		edge[i].lca = LCA(edge[i].x, edge[i].y);
		edge[i].len = dis[edge[i].x] + dis[edge[i].y] - 2 * dis[edge[i].lca];
	}
	int l = 0; int r = INFI;
	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}