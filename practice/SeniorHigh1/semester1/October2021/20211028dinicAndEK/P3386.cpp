#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
 
int k = 0;
int n = 0; int m = 0;
 
int edge[MAXN][MAXN] = { 0 };
int  used[MAXN] = { 0 };
int match[MAXN] = { 0 };
 
bool dfs(int x){
	for(int i = 1; i <= m; i++){
		if(edge[x][i] and !used[i]){
			used[i] = 1;
			if(!match[i] or dfs(match[i])){
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
 
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for(int i = 1; i <= k; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		edge[x][y] = 1;
	}
	
	int sum = 0;
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));
		if(dfs(i)){
			sum++;
		} 
	} 
	
	printf("%d\n", sum);
	return 0;
}
