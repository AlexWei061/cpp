#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000
#define MAXM 2 * MAXN

// P3379

int s = 0;
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
	for(int i = 0; i <= 30; i++){
		f[x][i + 1] = f[f[x][i]][i];
	}
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa){
			f[y][0] = x;
			prework(y, x);
		}
	}
}

int query(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 30; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) 
			x = f[x][i];
		if(x == y)
			return x;
	}
	for(int i = 30; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	
	prework(s, 0);
	
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
	
	return 0;
}