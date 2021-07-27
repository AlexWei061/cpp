#include<bits/stdc++.h>
using namespace std;

int board[100] = { 0 };
int n = 0;

int a[100] = { 0 };                 //第a列被占用的情况
int l[100] = { 0 };                 //向左的对角线被占用的情况 (同一个对角线上横纵坐标的和为定值: x+y = constant)
int r[100] = { 0 };                 //向右的对角线被占用的情况 (同一个对角线上横纵坐标的差为定值: x-y = constant)

int ans = 0; 
 
void dfs(int x){              //第x行的皇后 
	if(x > n){      //所有皇后已经放置 
		ans++;
		if(ans <= 3){              //输出答案 
			for(int i = 1; i <= n; i++){
				printf("%d ", board[i]);
			}
			puts("");
		}
		return;
	}
	
	for(int i = 1; i <= n; i++){                           //皇后的纵坐标y=i 
		int y = i;
		if(a[i] == 0 and l[x+y] == 0 and r[x-y+15] == 0){           //三个方向上都没有占用 
			board[x] = y;                                  //放置皇后 
			//做标记 
			a[y] = 1;
			l[x+y] = 1;
			r[x-y+15] = 1;
			
			dfs(x + 1);        //递归下一行
			
			//删标记
			a[y] = 0;
			l[x+y] = 0;
			r[x-y+15] = 0;
		} 
	}
} 

int main(){
	scanf("%d", &n);
	dfs(1);
	printf("%d", ans);
	return 0;
} 
