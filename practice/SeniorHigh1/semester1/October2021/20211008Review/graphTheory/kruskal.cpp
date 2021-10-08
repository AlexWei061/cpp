#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0; int m = 0;

struct Tedge{
	int x; int y;
	int value;
}edges[MAXM];
bool comp(Tedge a, Tedge b){
	return a.value < b.value;
}

int parent[MAXN] = { 0 };
void init(){
	for(int i = 0; i <= n; i++){
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

int tot = 0;
bool chosen[MAXM] = { 0 };
void kruskal(){
	sort(edges + 1, edges + m + 1, comp);
	for(int i = 1; i <= m; i++){
		int x = edges[i].x; int y = edges[i].y;
		if(findRoot(x) != findRoot(y)){
			unionVertices(x, y);
			chosen[i] = 1;
			tot += edges[i].value;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);

    init();
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].value);
	}

	kruskal();

	for(int i = 0; i < m; i++){
		if(chosen[i]){
			printf("x = %d y = %d v = %d\n", edges[i].x, edges[i].y, edges[i].value);
		}
	}
	printf("total value = %d\n", tot);

    return 0;
}
