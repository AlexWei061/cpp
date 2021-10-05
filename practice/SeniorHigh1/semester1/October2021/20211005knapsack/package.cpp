#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0; int m = 0;
int w[MAXN] = { 0 };
int c[MAXN] = { 0 };
int f[MAXN] = { 0 };

int knapsack01(int n, int m){
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= w[i]; j--){
			f[j] = max(f[j], f[j-w[i]] + c[i]);
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n ; i++){
		scanf("%d%d", &w[i], &c[i]);
	}

	printf("%d\n", knapsack01(n, m));

    return 0;
}

/*

一个旅行者有一个最多能用 m 公斤的背包，现在有 n 件物品，它们的重量分别为 Wi，他们的价值分别为 Ci。
若每种物品只有一件，求出旅行者能获得的最大总价值

4 10
2 1
3 3
4 5
7 9

12

*/