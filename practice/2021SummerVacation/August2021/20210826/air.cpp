#include<bits/stdc++.h>
using namespace std;

#define MAXN 10100

int n = 0, m = 0, k = 0;

int parent[MAXN] = { 0 };
int  rrank[MAXN] = { 0 };

struct Tedge{
	int x; int y;
	int value;
}edges[MAXN];

bool comp(Tedge a, Tedge b){
	return a.value < b.value;
}

void init(){
	for(int i = 1; i <= n; i++){
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

bool unionVertices(int x, int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if(xRoot == yRoot){
		return false;
	}
	else{
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
	return true;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].value);
	}

	if(n == k){
		printf("%d\n", 0);
		return 0;
	}

	if(k > n){
		printf("No Answer\n");
		return 0;
	}

	int ans = 0; int cnt = 0;
	sort(edges, edges+m, comp);
	init();
	for(int i = 0; i < m; i++){
		if(unionVertices(edges[i].x, edges[i].y)){
			ans += edges[i].value;
			cnt++;
			if(n - cnt == k){
				break;
			}
		}
	}

	if(n - cnt == k){
		printf("%d\n", ans);
	}
	else{
		printf("No Answer\n");
	}

	return 0;
}

/*

[题目描述]
给你云朵的个数 N，再给你 M 个关系，表示哪些云朵可以连在一起。

现在小杉要把所有云朵连成 K 个棉花糖，一个棉花糖最少要用掉一朵云，小杉想知道他怎么连，花费的代价最小。

[输入格式]
第一行有三个数 N, M, K

接下来 M 行每行三个数 X, Y, L，表示 X 云和 Y 云可以通过 L 的代价连在一起。

*/