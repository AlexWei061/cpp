#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
int gragh[MAXN][MAXN] = { 0 };

int parent[MAXN] = { 0 };                                          // parent[i] = root : i 节点的根节点为root
int   rank[MAXN] = { 0 };                                          // rank[i] : 以 i 为根节点的子树的深度

void initialize(int parent[], int rank[]){
	for(int i = 0; i < n; i++){
		parent[i] = -1;
		rank[i]   =  0;
	}
}

int findRoot(int x, int parent[]){                                 // 找到节点 X 的根节点
	while(parent[x] != -1){
		x = parent[x];
	}
	return x;
}

bool unionVertices(int x, int y, int parent[], int rank[]){        // 把 x 和 y 连起来
	int xRoot = findRoot(x, parent);
	int yRoot = findRoot(y, parent);
	if(xRoot == yRoot){
		return false;                                              // 已经在一起了说明图中有环
	}
	else{
		if(rank[xRoot] > rank[yRoot]){
			parent[yRoot] = xRoot;
		}
		else if(rank[yRoot] > rank[xRoot]){
			parent[xRoot] = yRoot;
		}
		else{
			parent[xRoot] = yRoot;
			rank[yRoot]++;
		}
	return true;
	}
}

int main(){
	
	return 0;
}
