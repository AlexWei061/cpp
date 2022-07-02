#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200
#define MAXM MAXN << 2

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
void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}


int dep[MAXN] = { 0 };
int f[MAXN][35] = { 0 };
void prework(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = 0; i <= 30; i++)
		f[x][i + 1] = f[f[x][i]][i];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		f[y][0] = x; prework(y, x);
	}
}

int query(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 30; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 30; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];	
	return f[x][0];
}

int cnt = 0;
struct Tpath{
	int t;
	int x, y, v;
	bool isd;
}path[MAXN];

int main(){
	n = in; m = in;
	for(int i = 1; i < n; i++){
		int x = in, y = in;
		add(x, y), add(y, x);
	} prework(1, 0);
	for(int i = 1; i <= m; i++){
		int op = in;
		if(op == 0){
			int a = in, b = in, v = in;
			path[++cnt].x = a, path[cnt].y = b, path[cnt].t = i, path[cnt].v = v;
		}
		else if(op == 1){
			int t = in;
			for(int j = 1; j <= cnt; j++) if(path[j].t == t) path[j].isd = 1;
		}
		else if (op == 2){
			int k = in; int ans = -1;
			for(int j = 1; j <= cnt; j++){
				if(path[j].isd) continue;
				int x = path[j].x, y = path[j].y;
				int lcaxy = query(x, y), lcaxk = query(x, k), lcaky = query(k, y);
				int disxy = dep[x] + dep[y] - 2 * dep[lcaxy];
				int disxk = dep[x] + dep[k] - 2 * dep[lcaxk];
				int disky = dep[k] + dep[y] - 2 * dep[lcaky];
				if(disxy != disxk + disky) ans = max(ans, path[j].v);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
