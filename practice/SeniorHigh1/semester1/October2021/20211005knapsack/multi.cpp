#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0; int m = 0;
int   w[MAXN] = { 0 };
int   c[MAXN] = { 0 };
int   x[MAXN] = { 0 };
int   f[MAXN] = { 0 };
int num[MAXN] = { 0 };

int multiKnapsack(int n, int m){
	for(int i = 1; i <= n; i++){
		memset(num, 0, sizeof(num));
		for(int j = w[i]; j <= m; j++){
			if(f[j] < f[j-w[i]] + c[i] and num[j-w[i]] < x[i]){
				f[j] = f[j-w[i]] + c[i];
				num[j] = num[j-w[i]] + 1;
			}
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &w[i], &c[i], &x[i]);
	}

	printf("%d\n", multiKnapsack(n, m));

	return 0;
}

/*

设有 n 种物品，每种物品有一个重量 Wi及一个价值 Ci。但每种物品的数量都可以大于
1 但是有限制的，第 i 种物品有 Xi个。

同时有一个背包，最大容量为 M，求解在不超过背包容量的情况下，如何放置物品，
可以使得放入背包的物品的价值和最大。

4 12
2 5 2
3 3 3
4 5 1
7 9 6

19

*/