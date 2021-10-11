#include<bits/stdc++.h>
using namespace std;

#define MAXN 20200
#define MAXM 100100

int n = 0; int m = 0;

struct Tedge{
	int x; int y;
	int val; 
}edge[MAXM];
bool comp(Tedge a, Tedge b){
	return a.val > b.val;
}

int parent[2 * MAXN] = { 0 };

void init(){
	for(int i = 0; i <= 2 * n + 1; i++){
		parent[i] = i;
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
	scanf("%d%d", &n, &m);
	init();
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].val);
	}
	
	sort(edge + 1, edge + m + 1, comp);
	
	for(int i = 1; i <= m; i++){
		if(findRoot(edge[i].x) != findRoot(edge[i].y)){
			unionVertices(edge[i].x, edge[i].y + n);
			unionVertices(edge[i].x + n, edge[i].y);
		}
		else{
			printf("%d\n", edge[i].val);
			return 0;
		}
	}
	
	printf("%d\n", 0);
	
	return 0;
}
