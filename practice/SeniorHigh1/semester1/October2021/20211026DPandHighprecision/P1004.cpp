#include<bits/stdc++.h>
using namespace std;
#define MAXN 15

int n = 0;
int mmap[MAXN][MAXN] = { 0 };

int f[MAXN][MAXN][MAXN][MAXN] = { 0 };

void dp(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<= n; j++){
			for(int p = 1; p <= n; p++){
				for(int q = 1; q <= n; q++){
					f[i][j][p][q] = max(max(f[i-1][j][p-1][q], f[i-1][j][p][q-1]), max(f[i][j-1][p-1][q], f[i][j-1][p][q-1])) + mmap[i][j] + mmap[p][q];
					if(i == p and j == q) f[i][j][p][q] -= mmap[i][j];
				}
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	int a = 0; int b = 0; int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	while(a != 0 or b != 0 or c != 0){
		mmap[a][b] = c;
		scanf("%d%d%d", &a, &b, &c);
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%-2d ", mmap[i][j]);
		}
		puts("");
	}
	*/
	dp();
	printf("%d\n", f[n][n][n][n]);
	return 0;
}
