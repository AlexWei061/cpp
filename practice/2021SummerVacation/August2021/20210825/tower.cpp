#include<bits/stdc++.h>
using namespace std;

int n = 0;
int tower[105][105] = { 0 };

int f[105][105] = { 0 };

// f[i][j] = max(f[i-1][j], f[i-1][j-1]) + a[i][j]
void dp(){
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= i; j++){
			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + tower[i][j];
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &tower[i][j]);
		}
	}

	dp();

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, f[n][i]);
	}

	printf("%d\n", ans);

	return 0;
}

/*

输入一个数塔, 求一个从上到下的路径使路径上的数字和最大

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 11

30

*/