#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

int n = 0;
double x[MAXN] = { 0 };
double y[MAXN] = { 0 };
double f[1 << MAXN][MAXN];

double w(int i, int j){	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])); }
double hamilton(){
	memset(f, 0x7f, sizeof(f)); f[1][0] = 0;
	for(int i = 1; i < 1 << n; i++)
		for(int j = 0; j < n; j++) if(i >> j & 1)
			for(int k = 0; k < n; k++) if((i ^ 1 << j) >> k & 1)
				f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + w(k, j));
	return f[(1 << n) - 1][n - 1];
}

int main(){
	scanf("%d", &n); n++;
	for(int i = 1; i < n; i++) scanf("%lf%lf", &x[i], &y[i]);
	double ans = hamilton(); printf("%.2lf\n", ans);
	return 0;
}