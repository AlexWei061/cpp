#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXM 100100

// P3367

int n = 0; int m = 0;
int parent[MAXN] = { 0 };

void init(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
}

int findRoot(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = findRoot(parent[x]);
}

void merge(int x, int y){
	parent[findRoot(x)] = findRoot(y);
}

int main(){
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= m; i++){
		int op = 0; int x= 0; int y = 0;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1){
			merge(x, y);
		}
		else if(op == 2){
			if(findRoot(x) == findRoot(y)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}