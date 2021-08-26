#include<bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n = 0, m = 0;

int buket[2 * MAXN] = { 0 };

int parent[MAXN] = { 0 };
int  rrank[MAXN] = { 0 };

void initialize(){
	for(int i = 1; i <= 2 * n; i++){
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
	if(xRoot == yRoot){
		return;
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
}

int main(){
	scanf("%d%d", &n, &m);
	initialize();
	for(int i = 0; i < m; i++){
		int p = 0, x = 0, y = 0;
		scanf("%d%d%d", &p, &x, &y);
        if(p == 0){
            unionVertices(x, y);
        }
        else{
        	unionVertices(x, y + n);
        	unionVertices(x + n, y);
        }
	}

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int iRoot = findRoot(i);
        //printf("%d ", iRoot);
        buket[iRoot]++;
    }
    for(int i = 1; i <= 2 * n; i++){
        if(buket[i]){
            ans++;
        }
    }
    //puts("");
    /*
    for(int i = 1; i <= n; i++){
        printf("%-2d ", parent[i]);
    }
    printf("\n");
    for(int i = n + 1; i <= 2 * n; i++){
        printf("%-2d ", parent[i]);
    }
    printf("\n");
    */
    printf("%d\n", ans);
	
	return 0;
}

/*

6 4 
1 1 4 
0 3 5 
0 4 6 
1 1 2

*/