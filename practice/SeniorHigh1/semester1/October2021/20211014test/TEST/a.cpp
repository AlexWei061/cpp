#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1010
#define MAXM 300300

int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x ;
}

int n = 0; int m = 0;
int k = 0;

struct Tedge{
	int x, y;
	int val; int idx;
	int times;
	bool used;
	bool operator < (const Tedge& b)const {
		return val < b.val;
	}
	bool operator > (const Tedge& b)const {
		return val > b.val;
	}
}edge[MAXM];
bool comp(Tedge a, Tedge b){
	return a.val > b.val;
}

int parent[MAXN] = { 0 };
void init(){
	for(int k = 1; k <= n; k++){
		parent[k] = k;
	}
}

int findRoot(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = findRoot(parent[x]);
}

void unionVertices(int x, int y){
	parent[findRoot(x)] = findRoot(y);
}

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; i++){
		edge[i].x = read(); edge[i].y = read();
		edge[i].val = read(); edge[i].idx = i;
	}
	
	sort(edge+1, edge+m+1, comp);
	for(int i = 1; i <= k; i++){
		init();
		for(int j = 1; j <= m; j++){
			Tedge e = edge[j];
			if(!e.used and findRoot(e.x) != findRoot(e.y)){
				unionVertices(e.x, e.y);
				edge[j].used = 1;
				edge[e.idx].times = i;
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		printf("%d\n", edge[i].times);
	}
	
	return 0;
}
