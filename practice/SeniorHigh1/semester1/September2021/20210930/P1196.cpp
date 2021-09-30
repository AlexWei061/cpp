#include<bits/stdc++.h>
using namespace std;

#define MAXN 30300

int T = 0;
int ans = 0;

int parent[MAXN] = { 0 };
int distan[MAXN] = { 0 };
int   size[MAXN] = { 0 };

void init(){
	for(int i = 1; i <= MAXN; i++){
		parent[i] = i;
		distan[i] = 0;
		size[i]   = 1;
	}
}

int findRoot(int x){
	if(parent[x] == x){
		return x;
	}
	int root = findRoot(parent[x]);
	distan[x] += distan[parent[x]];
	return parent[x] = root;
}

void unionVertices(int x, int y){
	x = findRoot(x); y = findRoot(y);
	distan[x] += size[y];
    parent[x] = y;
	size[y] += size[x];
    size[x] = 0;
}

int main(){
	init();
	
	scanf("%d", &T);
    //printf("T = %d\n", T);
	for(int i = 1; i <= T; i++){
        scanf("\n");
		char op; int x = 0; int y = 0;
		scanf("%c%d%d", &op, &x, &y);
        //printf("op = %c\n", op);
		if(op == 'M'){
			unionVertices(x, y);
		}	
		else{
			if(findRoot(x) == findRoot(y)){
				printf("%d\n", abs(distan[x] - distan[y]) - 1);
			}
			else{
				printf("%d\n", -1);
			}
		}
	}
	
	return 0;
}