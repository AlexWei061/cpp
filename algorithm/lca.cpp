#include<bits/stdc++.h>
using namespace std;

/*
LCA - Lowest Common Ancestor
*/

#define N 40009
#define log2N 16

int f[N][log2N + 1];       //f[u][x] means node u goes up 2^x steps
int deep[N];                 //deep[v] means the septh of node v

/*adjacency list*/
int Next[2 * N];         //Next[i] means the next edge of i-th edge
int first[N + 5];          //first[i] means the first egde of i-th node
int to[2 * N];         //to[i] means the node that the i-th egde points to

int tot = 0;

void Add(int u, int v){    //bulid adjacency list 
	Next[++tot] = first[u]; first[u] = tot; to[tot] = v;
	Next[++tot] = first[v]; first[v] = tot; to[tot] = u;
}

void initialise(int node, int father_of_node){  //claculate every node reached by x square steps of each node jumping up tow
	deep[node] = deep[father_of_node] + 1;
	for(int i = 0; i <= log2N - 1; i++){
		f[node][i + 1] = f[f[node][i]][i];       //Going two to the x once is the same thing as going two to the x minus one twice
	}
	//eunmerate all edges of a node
	for(int edge = first[node]; edge != 0; edge = Next[edge]){
		int pointed_node = to[edge];
		if(pointed_node == father_of_node){
			continue;
		}
		f[pointed_node][0] = node;       //node is pointed_node's father
		initialise(pointed_node, node); 
	}
}

int LCA(int u, int v){             //find the lowest common ancestor of node u and v
	if(deep[u] < deep[v]){         //make sure u'depth is higer than v
		swap(u, v);
	}
	//jump
	for(int i = log2N; i >= 0; i--){
		if(deep[f[u][i]] >= deep[v]){     //haven't got to the same depth
			u = f[u][i];
		}
		
		if(u == v){                      //u and v are in the same chain
			return v;
		}
	}
	
	for(int i = log2N; i >= 0; i--){       //u and v have tha same depth now	
		if(f[u][i] != f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];          //u and v's lca must be the father of u and v now
}

int main(){
	
	int root = 1;
	
	int tree[6][5] = {
		{1, -1},
		{1,  2},
		{1,  3},
		{2,  4},
		{2,  5},
		{5,  6}
	};
	
	for(int i = 0; i < 6; i++){
		int u = tree[i][0];
		int v = tree[i][1];
		if(v != -1){
			Add(u, v);
		}
		else{
			root = u;
		} 
	}
	
	initialise(root, 0);
	
	for(int i = 1 ; i <= 6; i++){
		printf("node%d's depth is : %d\n", i, deep[i]);
	}
	
	printf("\n");
	
	for(int i = 1; i <= 6; i++){
		printf("node%d : ", i);
		for(int j = 0; j < log2N; j++){
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	
	int a = 3;
	int b = 5;
	printf("%d and %d's lca is %d\n", a, b, LCA(3, 5));
	
	return 0;
}
