#include<bits/stdc++.h>
using namespace std;
#define MAXN 50
#define MAXM 20020

int v = 0; int n = 0;
int w[MAXN] = { 0 };

int f[MAXN][MAXM] = { 0 };
void dp(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= v; j++)
			if(j < w[i]) 
				f[i][j] = f[i-1][j];
			else
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + w[i]);
}

int main(){
	scanf("%d", &v);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	} 
	dp();
	printf("%d\n", v - f[n][v]);
	return 0;
}
