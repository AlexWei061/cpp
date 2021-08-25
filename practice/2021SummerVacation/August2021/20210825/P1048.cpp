#include<bits/stdc++.h>
using namespace std;

#define T 1010
#define M 105

int t, m;
int w[M] = { 0 };
int v[M] = { 0 };

int f[M][T] = { 0 };

void dp(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= t; j++){
			if(j >= w[i]){
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);
			}
			else{
				f[i][j] = f[i-1][j];
			}
		}
	}
}

int main(){
	scanf("%d%d", &t, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &w[i], &v[i]);
	}

	dp();

	int ans = f[m][t];
	printf("%d\n", ans);

	return 0;
}