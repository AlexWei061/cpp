#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define MAXM MAXN * (MAXN - 1)

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

int tot = 0;
void kruskal(){
	sort(edge, edge+m, comp);
	for(int i = 0; i < m; i++){
		Tedge e = edge[i];
		if(findRoot(e.x) != findRoot(e.y)){
			unionVertices(e.x, e.y);
			tot += e.value;
		}
	}
}

int main(){
	scanf("%d", &n);	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int temp = 0;
			scanf("%d", &temp);
			if(temp){
				edge[m++] = (Tedge){i, j, temp};
			}
		}
	}
	
	init();
	
	kruskal();
	
	printf("%d\n", tot);
	
	return 0;
}