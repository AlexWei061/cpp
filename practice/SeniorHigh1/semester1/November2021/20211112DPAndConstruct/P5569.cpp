#include<bits/stdc++.h>
using namespace std;
#define MAXN 4040
#define endl '\n'

// 60 pts

int n = 0;
int a[MAXN] = { 0 };

int sum[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };
void dp(){
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++){
		f[i][i] = 0; sum[i] = sum[i-1] + a[i];
	}
	for(int len = 2; len <= n; len++)                                // 阶段 
		for(int l = 1; l <= n - len + 1; l++){                       // 状态：左端点 
			int r = l + len - 1;                                     // 状态：右端点 
			for(int k = l; k < r; k++)                               // 决策 
				f[l][r] = min(f[l][r], f[l][k] + f[k+1][r]);
			f[l][r] += sum[r] - sum[l-1];
		}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp();
	cout << f[1][n] << endl;
	return 0;
}