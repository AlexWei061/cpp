#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 2002000

int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9')c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int a[MAXN] = { 0 };

int f[MAXN][60] = { 0 };

void prework(){
	for(int i = 1; i <= n; i++){
		f[i][0] = a[i];
	}
	int t = log(n) / log(2) + 1;
	for(int j = 1; j < t; j++){
		for(int i = 1; i <= n - (1 << j) + 1; i++){
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++){
		a[i] = in;
	}
	prework();
	for(int i = 1; i <= m; i++){
		int l = in; int r = in;
		printf("%d\n", query(l, r));
	}
	return 0;
}
