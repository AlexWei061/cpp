#include<bits/stdc++.h>
using namespace std;

#define MAXN 105

const int px[5] = { 0, 1, 0, -1, 0 };
const int py[5] = { 0, 0, 1, 0, -1 };

int r = 0;
int c = 0;
int mmap[MAXN][MAXN] = { 0 };
int  way[MAXN][MAXN] = { 0 };
int    f[MAXN][MAXN] = { 0 };

int ans = 0;
void dfs(int x, int y, int step){
	ans = max(ans, step);
	//printf("	x = %d y = %d s = %d\n", x, y, step);
	for(int i = 1; i <= 4; i++){
		int nx = x + px[i];
		int ny = y + py[i];
		if(nx >= 1 and nx <= r and ny >= 1 and ny <= c and !way[nx][ny] and mmap[x][y] > mmap[nx][ny]){
			way[nx][ny] = 1;
			dfs(nx, ny, step+1);
			way[nx][ny] = 0;
		}
	}
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", &mmap[i][j]);
		}
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			dfs(i, j, 1);
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9


*/