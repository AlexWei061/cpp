#include<bits/stdc++.h>
using namespace std;
#define MAXN 50
#define MAXM 50
#define int long long

const int px[10] = { 0, 1, 2,  2,  1, -1, -2, -2, -1 };
const int py[10] = { 0, 2, 1, -1, -2, -2, -1,  1,  2 };

int n, m;
int a, b;

int f[MAXN][MAXM] = { 0 };

bool canGo(int a, int b, int x, int y){
	if(a == x and b == y) return false;
	for(int i = 1; i <= 8; i++){
		if(x == a + px[i] and y == b + py[i]) return false;
	}
	return true;
}

void dp(){
	f[0][0] = 1ll; f[a][b] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 and j == 0) continue;
			if(canGo(a, b, i, j)){
				if(j == 0) f[i][0] = f[i-1][0];
				if(i == 0) f[0][j] = f[0][j-1];
				else f[i][j] = f[i-1][j] + f[i][j-1];
			}
		}
	}
}

signed main(){
	scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
	dp();
	/*
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			printf("%lld ", f[i][j]);
		}
		puts("");
	}
	*/
	printf("%lld\n", f[n][m]);
	return 0;
}
