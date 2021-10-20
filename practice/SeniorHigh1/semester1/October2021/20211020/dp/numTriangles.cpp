#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

// P1216

int n = 0;
int num[MAXN][MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<= i; j++){
			scanf("%d", &num[i][j]);
		}
	}
	f[1][1] = num[1][1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			f[i][j] = max(f[i-1][j], f[i-1][j-1]) + num[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, f[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
