#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0; int m = 0;
int c[MAXN] = { 0 };
int w[MAXN] = { 0 };
int f[MAXN] = { 0 };

int knapsack(int n, int m){
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++){
			f[j] = max(f[j], f[j-w[i]] + c[i]);
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &w[i], &c[i]);
	}
	printf("%d\n", knapsack(n, m));
	return 0;
}
