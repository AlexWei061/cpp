#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 100100

int n = 0; int m = 0;

bool isT[MAXN];
int parent[MAXM] = { 0 };

void init(){
	for(int i = 0; i <= m; i++){
		parent[i] = i;
	}
}

int findRoot(int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = findRoot(parent[x]);
}

void unionVertices(int x, int y){
	parent[findRoot(x)] = findRoot(y);
}

int main(){
	freopen("talk.in", "r", stdin);
	freopen("talk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	//printf("n = %d m = %d\n", n, m);

	init();

	/*
	for(int i = 1; i <= m; i++){
		printf("%d ", parent[i]);
	}
	puts("");
	*/

	for(int i = 1; i <= n; i++){
		int k = 0;
		scanf("%d", &k);
		//printf("	k = %d\n", k);
		if(k == 0){
		    printf("NO\n");
		    return 0;
		}
		int L[MAXN] = { 0 };
		for(int j = 1; j <= k; j++){
			scanf("%d", &L[j]);
			isT[L[j]] = true;
			//printf("		L[%d] = %d\n", j, L[j]);
			if(j >= 2 and findRoot(L[j]) != findRoot(L[j-1])){
				unionVertices(L[j], L[j-1]);
			}
		}
	}

	/*
	for(int i = 1; i <= m; i++){
		printf("%d ", parent[i]);
	}
	puts("");
	*/
	
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(isT[i] and parent[i] == i){
			cnt++;
		}
		if(cnt >= 2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
