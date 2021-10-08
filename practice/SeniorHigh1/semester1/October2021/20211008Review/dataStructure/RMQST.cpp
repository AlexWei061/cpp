#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
int a[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

/* f[i][j] = max{f[i][j-1], f[i + 2^(j-1)][j-1]} */
void preworkST(){
	for(int i = 1; i <= n; i++){
		f[i][0] = a[i];
	}
	int t = (log(n) / log(2)) + 1;
	for(int j = 1; j < t; j++){
		for(int i = 1; i <= n - (1 << j); i++){
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	preworkST();
	
	printf("%d\n", query(3, 5));
	
	return 0;
}
