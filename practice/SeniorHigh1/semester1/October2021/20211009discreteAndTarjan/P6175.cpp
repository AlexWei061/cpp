#include<bits/stdc++.h>
using namespace std;

#define INFI 1e8
#define MAXN 200

int n = 0; int m = 0;
int mmap[MAXN][MAXN] = { 0 };
int  dis[MAXN][MAXN] = { 0 };

int main(){
	int ans = INFI;
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i != j){
				mmap[i][j] = INFI;
				dis[i][j] = INFI;	
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0; int w = 0;
		scanf("%d%d%d", &x, &y, &w);
		dis[x][y] = w; dis[y][x] = w;
		mmap[x][y] = w; mmap[y][x] = w;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i < k; i++){
			for(int j = i + 1; j < k; j++){
				ans = min(ans, dis[i][j] + mmap[i][k] + mmap[k][j]);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	
	if(ans == INFI){
		printf("No solution.\n");
	}
	else{
		printf("%d\n", ans);
	}
	
	return 0;
}
