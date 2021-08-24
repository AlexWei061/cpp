#include<bits/stdc++.h>
using namespace std;

int n = 0;
int m = 0;

int mmap[25][25] = { 0 };
int    f[25][25] = { 0 };

void work(){
	if(mmap[1][1] = 1){
		printf("%d\n", 0);
	}
	else{
		f[1][1] = 1;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(mmap[i][j]){
				f[i][j] = 0;
			}
			else{
				f[i][j] = f[i-1][j] + f[i-1][j-1];
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		mmap[x][y] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += f[n][i];
	}

	printf("%d\n", ans);

	return 0;
}