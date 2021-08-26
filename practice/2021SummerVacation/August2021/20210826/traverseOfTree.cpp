#include<bits/stdc++.h>
using namespace std;

char tree[10010];

void preorder(char* tree, int node){
	printf("%c", tree[node]);
	if(tree[node*2+1] != '#'){
		preorder(tree, node*2+1);
	}
	if(tree[node*2+2] != '#'){
		preorder(tree, node*2+2); 
	} 
}

void inorder(char* tree, int node){
	if(tree[node*2+1] != '#'){
		inorder(tree, node*2+1);
	}
	printf("%c", tree[node]);
	if(tree[node*2+2] != '#'){
		inorder(tree, node*2+2); 
	} 
}

void postorder(char* tree, int node){
	if(tree[node*2+1] != '#'){
		postorder(tree, node*2+1);
	}
	if(tree[node*2+2] != '#'){
		postorder(tree, node*2+2); 
	} 
	printf("%c", tree[node]);
}

int main(){
	memset(tree, '#', sizeof(tree));
	scanf("%s", tree);
	preorder(tree, 0);
	puts("");
	inorder(tree, 0);
	puts("");
	postorder(tree, 0);
	puts("");
	return 0;
}

/*

先序, 中序, 后序遍历

ABCDEF###G##H##

ABDEGCFH
DBGEAFHC
DGEBHFCA

*/