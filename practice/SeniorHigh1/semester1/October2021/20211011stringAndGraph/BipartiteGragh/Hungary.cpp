#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

/* 匈牙利算法 二分图最大匹配 */

int k = 0;                                  // 总边数 
int n = 0; int m = 0;                       // n为 X 集中的节点数 m 为 Y 集中度节点数 

int edge[MAXN][MAXN] = { 0 };
int  used[MAXN] = { 0 };
int match[MAXN] = { 0 };

bool dfs(int x){
	for(int i = 1; i <= m; i++){
		if(edge[x][i] and !used[i]){              // 如果有边且没有被选择过 
			used[i] = 1;                          // 标记被选择过 
			if(!match[i] or dfs(match[i])){       // 如果没有被匹配过 或者 匹配他的还有能够匹配到的 
				match[i] = x;                     // 标记被 x 匹配了
				return 1;                         // 匹配成功 
			}
		}
	}
	return 0;                                     // 匹配失败 
}

int main(){
	scanf("%d", &k);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= k; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		edge[x][y] = 1;                     // x 到 y 有一条边 x -> y
	}
	
	int sum = 0;                            // 最大匹配
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));      // 每一轮清空 used 数组
		if(dfs(i)){
			sum++;
		} 
	} 
	
	printf("%d\n", sum);
	return 0;
}
