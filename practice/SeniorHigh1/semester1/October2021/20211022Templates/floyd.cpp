#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

// B3611

int n = 0;
int mmap[MAXN][MAXN] = { 0 };

int f[MAXN][MAXN] = { 0 };

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &mmap[i][j]);
			f[i][j] = mmap[i][j];
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = f[i][j] or f[i][k] and f[k][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", f[i][j]);
		}
		puts("");
	}
	
	return 0;
}