#include<bits/stdc++.h>
using namespace std;

#define M 205
#define N 305

int m/*背包容量*/, n/*物品个数*/;

int w[N] = { 0 };       //  weight
int v[N] = { 0 };       //  value

int f[N][M] = { 0 };

/*
f[i][j] : 第 i 个物品, 剩余空间为 j
f[i][j] = max{f[i-1][j], f[i-1][j-w[i]] + v[i]}  (j >= w[i])
        = f[i-1][j]                              (j <  w[i])
*/
void dp(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j >= w[i]){
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
			}
			else{
				f[i][j] = f[i-1][j];
			}
		}
	}
}

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &w[i], &v[i]);
	}

	dp();

	int ans = f[n][m];
	printf("%d\n", ans);
	return 0;
}