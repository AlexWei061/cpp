#include<bits/stdc++.h>
using namespace std;
#define MAXN 2020
#define endl '\n'

int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int n = 0; int m = 0;

int ans = 0;
int f[MAXN][MAXN] = { 0 };
void dp(){
	for(int i = 1; i <= n; i++){
		int minx = f[i-1][1];
		for(int j = 1; j <= n; j++){
			minx = min(minx, f[i-1][j]);
			f[i][j] = minx + abs(b[j] - a[i]);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
	sort(b+1, b+n+1); m = unique(b+1, b+n+1) - b - 1;
	dp(); ans = f[n][1];
	for(int i = 2; i <= m; i++) ans = min(ans, f[n][i]);
	reverse(a+1, a+n+1); dp();
	for(int i = 1; i <= m; i++) ans = min(ans, f[n][i]);
	cout << ans << endl;
	return 0;
}