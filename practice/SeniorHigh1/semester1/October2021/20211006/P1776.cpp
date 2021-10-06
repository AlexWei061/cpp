#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int m = 0;
int w[MAXN] = { 0 };
int c[MAXN] = { 0 };
int x[MAXN] = { 0 };
int f[MAXN] = { 0 };

int multiKnapsack(int n, int m){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x[i]; x[i] -= j, j <<= 1){
			for(int k = m; k >= w[i] * j; k--){
				f[k] = max(f[k], f[k - w[i] * j] + c[i] * j);
			}
		}
		if(x[i]){
			for(int k = m; k >= w[i] * x[i]; k--){
				f[k] = max(f[k], f[k - w[i] * x[i]] + c[i] * x[i]);
			}
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &c[i], &w[i], &x[i]);
	}

	printf("%d\n", multiKnapsack(n, m));
	return 0;
}