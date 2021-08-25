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

int dfs(int x, int y){
	if(f[x][y] > 0){
		return f[x][y];
	}
	int t = 1;
	for(int i = 1; i <= 4; i++){
		int nx = x + px[i];
		int ny = y + py[i];
		if(nx >= 1 and nx <= r and ny >= 1 and ny <= c and mmap[x][y] < mmap[nx][ny]){            //倒着往回搜
			int temp = dfs(nx, ny) + 1;
			if(temp > t){
				t = temp;
			}
		}
	}
	f[x][y] = t;
	return t;
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
			int t = dfs(i, j);
			if(t > ans){
				ans = t;
			}
		}
	}
	printf("%d\n", ans);
}


/*

90 : TLE

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
*/

/*

小明喜欢滑雪，因为滑雪的确很刺激，可是为了获得速度，滑的区域必须向下倾斜，当小明滑到坡底，
不得不再次走上坡或等着直升机来载他，小明想知道在一个区域中最长的滑坡。滑坡的长度由滑过点的个数来计算，
区域由一个二维数组给出，数组的每个数字代表点的高度。下面是一个例子：

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小，在上面的例子中，一条可行的滑坡为25-24-17-16-1（从25开始到1结束），
当然25-24……2…1更长，事实上这是最长的一条。

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

25

*/