#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };

int f[MAXN][MAXN] = { 0 };
void dp(){                                     // O(n^2)
	for(int i = 1; i <= n; i++){
		f[i][0] = 0; f[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == b[j])
				f[i][j] = max(max(f[i][j], f[i-1][j-1] + 1), max(f[i][j-1], f[i-1][j]));
			else
				f[i][j] = max(f[i][j-1], max(f[i-1][j], f[i][j]));
		}
	}
	printf("%d\n", f[n][n]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}
	dp();
	return 0;
}
