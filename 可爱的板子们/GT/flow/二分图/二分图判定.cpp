#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 100100
#define MAXM 2 * MAXN
 
int n = 0; int m = 0;
 
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
 
void add(int x, int y){                             // 邻接表 没什么好说的 
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}
 
int color[MAXN] = { 0 };
 
bool dfs(int x, int c){                             // 尝试把节点 x 染成 c 并返回是否染色成功 
	color[x] = c;                                   // 染色
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(color[y] == c){
			return false;                           // 连出去的点和自身的颜色相同 染色失败 
		}
		if(color[y] == 0 and !dfs(y, -c)){
			return false;                           // 如果相邻的节点没有被染色 但是给他染上和自己相反的颜色却失败了 则染色失败 
		}
	} 
	return true;                                    // 染色成功  
}
 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	
	for(int i = 1; i <= n; i++){
		if(color[i] == 0){                          // 如果没被染色      
			if(!dfs(i, 1)){
				printf("NO\n");                     // 染色不成功 说明不是二分图 
				return 0;
			} 
		}
	}
	printf("YES\n");                                // 所有点都染色成功 说明是二分图 
	return 0;
}
