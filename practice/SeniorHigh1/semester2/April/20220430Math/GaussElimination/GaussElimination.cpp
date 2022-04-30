#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define EPS 1e-7

int n = 0;
double mmap[MAXN][MAXN] = { 0 };
double ans[MAXN] = { 0 };

void solve(){
	for(int i = 1; i <= n; i++){
		int r = i;
		for(int j = i + 1; j <= n; j++)
			if(fabs(mmap[r][i]) < fabs(mmap[j][i])) r = j;
		if(fabs(mmap[r][i]) < EPS) { cout << "No Solution\n"; goto end; }
		if(i != r) swap(mmap[i], mmap[r]);
		double div = mmap[i][i];
		for(int j = i; j <= n + 1; j++) mmap[i][j] /= div;
		for(int j = i + 1; j <= n; j++){
			div = mmap[j][i];
			for(int k = i; k <= n + 1; k++) mmap[j][k] -= div * mmap[i][k];
		}
	}
	ans[n] = mmap[n][n + 1];
	for(int i = n - 1; i >= 1; i--){
		ans[i] = mmap[i][n + 1];
		for(int j = i + 1; j <= n; j++) ans[i] -= mmap[i][j] * ans[j];
	}
	for(int i = 1; i <= n; i++) printf("%.2lf\n", ans[i]);
	end : return;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n + 1; j++)
			cin >> mmap[i][j];
	solve();
	return 0;
}