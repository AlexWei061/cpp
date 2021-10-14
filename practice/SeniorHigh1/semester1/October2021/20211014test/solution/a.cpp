#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010
#define MAXM 300300
#define MAXK 10010

inline int read(){
	int p = 0; int f = 1;
	char c = getchar();
	while(c > '9' or c<'0'){
		if(c == '-') f =- 1;
		c = getchar();
	}
	while(c >= '0' and c <= '9'){
		p = p * 10 + c - '0';
		c=getchar();
	}
	return p * f;
}

int n = 0; int m = 0;
int k = 0;
struct Tedge{
	int x, y;
	int val; int idx;
}edge[MAXM];
bool comp(Tedge a, Tedge b){
	return a.val > b.val; 
}

int parent[MAXN][MAXK] = { 0 };

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			parent[i][j] = i;
		}
	}
}

int findRoot(int x, int kth){
	if(x == parent[x][kth]){
		return x;
	}
	return parent[x][kth] = findRoot(parent[x][kth], kth);
}

int vis[MAXM] = { 0 };
int cur[MAXN][MAXN] = { 0 };

int main(){
	n = in; m = in; k = in;
	init();
	for(int i = 1; i <= m ;i++){
		edge[i].x = in; edge[i].y = in;
		edge[i].val = in; edge[i].idx = i;
	}
	sort(edge+1, edge+m+1, comp);
	
	for(int i = 1; i <= m; i++){
		int x = edge[i].x; int y = edge[i].y;
		int t = cur[x][y] + 1;
		int xRoot = findRoot(x, t); int yRoot = findRoot(y, t);
		while(xRoot == yRoot and t < k){
			t++; xRoot = findRoot(x, t); yRoot = findRoot(y, t);
		}	
		if(xRoot == yRoot) continue;
		vis[edge[i].idx] = t;
		parent[yRoot][t] = xRoot;
		cur[x][y] = t; cur[y][x] = t;
	}
	
	for(int i = 1; i <= m; i++){
		printf("%d\n", vis[i]);
	}
	
	return 0;
}
