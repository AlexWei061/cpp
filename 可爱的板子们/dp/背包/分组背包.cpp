#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010

int n = 0; int m = 0;
int x[MAXN] = { 0 };
int w[MAXN][MAXN] = { 0 };
int c[MAXN][MAXN] = { 0 };
int f[MAXN] = { 0 };

int groupKnapsack(int n, int m){
	for(int i = 1; i<= n; i++){
		for(int j = m; j >= 0; j--){
			for(int k = 1; k <= x[i]; k++){
				if(j > w[i][k]){
					f[j] = max(f[j], f[j-w[i][k]] + c[i][k]);
				}
			}
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d\n", &x[i]);
		for(int j = 1; j <= x[i]; j++){
			scanf("%d%d", &w[i][j], &c[i][j]);
		}
	}

	printf("%d\n", groupKnapsack(n, m));

	return 0;
}

/*

给定 n 组物品，第 i 组有 Xi个物品，第 i 组的第 j 个物品有重量 Wij 及一个价值 Cij 。
同时有一个背包，最大容量为 M，在不超过背包容量的情况下，每组最多选择一个物
品，求解在如何放置物品，可以使得放入背包的物品的价值和最大。

4 12
2 5 2 3 6
3 1 3 2 5 5 3
4 5 1 2 7 6 8 3 6
6 9 6 10 3 2 10 7 12 11 11 4 20

38

*/

