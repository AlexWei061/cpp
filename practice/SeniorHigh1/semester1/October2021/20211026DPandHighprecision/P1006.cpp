#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MAXM 101

int n = 0; int m = 0;
int mmap[MAXN][MAXM] = { 0 };
//int f[MAXN][MAXM][MAXN][MAXM] = { 0 };
int f[MAXN+MAXM][MAXN][MAXM] = { 0 };

/*
void dp(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int p = 1; p <= n; p++){
				for(int q = 1; q <= m; q++){
					f[i][j][p][q] = max(max(f[i-1][j][p-1][q], f[i-1][j][p][q-1]), max(f[i][j-1][p][q-1], f[i][j-1][p-1][q])) + mmap[i][j] + mmap[p][q];
					if(i == p and j == q) f[i][j][p][q] -= mmap[i][j];
				}
			}
		}
	}
}
*/

void dp(){
	for(int k = 1; k < n + m; k++){
		for(int i = 1; i <= n; i++){
			for(int p = 1; p <= n; p++){
				if(k - i < 0 or k - p < 0) continue;
				f[k][i][p] = max(max(f[k-1][i][p], f[k-1][i-1][p-1]), max(f[k-1][i-1][p], f[k-1][i][p-1])) + mmap[i][k-i+1] + mmap[p][k-p+1];
				if(i == p) f[k][i][p] -= mmap[i][k-i+1];
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &mmap[i][j]);
		}
	}

	dp();
	printf("%d\n", f[n+m-1][n][n]);
	return 0;
}
