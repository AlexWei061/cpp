#include<bits/stdc++.h>
using namespace std;
#define MAXN 5050
#define MAXM 5050
#define INFI 0x3f3f3f3f

int ans = 0; 
int n = 0; int k = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int size[MAXN] = { 0 };
int f[MAXN][MAXN][10] = { 0 };
void dfs(int x, int fa){
	size[x] = 1;
	f[x][1][0] = 0; f[x][1][1] = 0; f[x][1][2] = 0;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y == fa) continue;
		dfs(y, x);
		for(int j = size[x]; j; j--){
			for(int k = size[y]; k; k--){
				f[x][j+k][2] = min(f[x][j+k][2], f[x][j][0] + f[y][k][2] + 2 * value[e]);
				f[x][j+k][2] = min(f[x][j+k][2], f[x][j][1] + f[y][k][1] + value[e]);
				f[x][j+k][2] = min(f[x][j+k][2], f[x][j][2] + f[y][k][0] + 2 * value[e]);
				
				f[x][j+k][1] = min(f[x][j+k][1], f[x][j][0] + f[y][k][1] + value[e]);
				f[x][j+k][1] = min(f[x][j+k][1], f[x][j][1] + f[y][k][0] + 2 * value[e]);
				
				f[x][j+k][0] = min(f[x][j+k][0], f[x][j][0] + f[y][k][0] + 2 * value[e]);
			}
		}
		size[x] += size[y];
	}
	ans = min(ans, f[x][k][2]);
}

int main(){
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w); add(y, x, w);
	}
	
	ans = INFI;
	memset(f, 0x3f, sizeof(f));
	
	dfs(1, 0);
	
	printf("%d\n", ans);
	
	return 0;
}
