#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 10010

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

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
				return true;
			}
		}
	}
	return false;
}
 
int main(){
	n = in; m = in; k = in;
	for(int i = 1; i <= k; i++){
		int x = in; int y = in;
		edge[x][y] = 1;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));
		if(dfs(i)) sum++;
	} 
	cout << sum << '\n';
	return 0;
}