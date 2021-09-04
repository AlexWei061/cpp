#include<bits/stdc++.h>
using namespace std;

#define MAXN 305
#define MAXM 8080

int n = 0, m = 0;

struct Tedge{
	int x, y;
	int value;
}edge[MAXM];

bool comp(Tedge a, Tedge b){
	return a.value < b.value;
}

int parent[MAXN] = { 0 };
int  rrank[MAXN] = { 0 };

void init(){
	for(int i = 0; i <= n; i++){
		parent[i] = -1;
		rrank[i]  =  0;
	}
}

int findRoot(int x){
	while(parent[x] != -1){
		x = parent[x];
	}
	return x;
}

void unionVertices(int x, int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if(xRoot != yRoot){
		if(rrank[xRoot] > rrank[yRoot]){
			parent[yRoot] = xRoot;
		}
		else if(rrank[xRoot] < rrank[yRoot]){
			parent[xRoot] = yRoot;
		}
		else{
			parent[xRoot] = yRoot;
			rrank[yRoot]++;
		}
	}
}

/*
runtime complexity : O(nlogn + n)
*/

int ans = 0;
int chosen[MAXM] = { 0 };
void kruskal(){
	sort(edge, edge+m, comp);
	for(int i = 0; i < m; i++){
		Tedge e = edge[i];
		if(findRoot(e.x) != findRoot(e.y)){
			unionVertices(e.x, e.y);
			chosen[i] = 1;
			ans = max(ans, e.value);
		}
	}
}

int main(){
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	scanf("%d%d", &n, &m);

	init();
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].value);
	}
	
	kruskal();
	printf("%d %d\n", n-1, ans); 
	
	return 0;
}