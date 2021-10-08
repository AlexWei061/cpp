#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
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

int main(){
	
	return 0;
}
