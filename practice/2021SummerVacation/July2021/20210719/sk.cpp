#include<bits/stdc++.h>
using namespace std;

int N, W;

int w[101] = { 0 };
int v[101] = { 0 };

int f[101][10001] = { 0 };

void kap(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= W; j++){
			if(j < w[i]){
				f[i][j] = f[i-1][j];
			}
			else if(j >= w[i]){
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);
			}
		}
	}
}

int main(){
	freopen("sk.in", "r", stdin);
	freopen("sk.out", "w", stdout);
	memset(f, 0, sizeof(f));
	scanf("%d%d", &N, &W);
	for(int i = 1; i <= N; i++){
		scanf("%d%d", &w[i], &v[i]);
	}
	kap();
	/*
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= W; j++){
			printf("%d ", f[i][j]);
		}
		puts("");
	}
	*/
	
	printf("%d", f[N][W]);
	
	return 0;
}
