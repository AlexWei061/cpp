#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define EPS 1e-7

int n = 0;
double a[MAXN][MAXN] = { 0 };
double mmap[MAXN][MAXN] = { 0 };
double ans[MAXN] = { 0 };

void solve(){
	for(int i = 1; i <= n; i++){
		int r = i;
		for(int j = i + 1; j <= n; j++)
			if(fabs(mmap[r][i]) < fabs(mmap[j][i])) r = j;
			
		if(r != i) swap(mmap[i], mmap[r]);
		double div = mmap[i][i];
		for(int j = i; j <= n + 1; j++) mmap[i][j] /= div;
		for(int j = i + 1; j <= n; j++){
			div = mmap[j][i];
			for(int k = i; k <= n + 1; k++) mmap[j][k] -= mmap[i][k] * div;
		}
	}
	ans[n] = mmap[n][n + 1];
	for(int i = n - 1; i >= 1; i--){
		ans[i] = mmap[i][n + 1];
		for(int j = i + 1; j <= n; j++) ans[i] -= mmap[i][j] * ans[j];
	}
	for(int i = 1; i <= n; i++) printf("%.3lf ", ans[i]); puts("");
}

int main(){
	cin >> n;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			mmap[i][j] = 2 * (a[i][j] - a[i + 1][j]);
			mmap[i][n + 1] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
		}
	solve();
	return 0;
}