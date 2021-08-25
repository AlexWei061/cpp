#include<bits/stdc++.h>
using namespace std;

#define INFI (int)1e5 + 100

int n = 0;
int m = 0;

int x[INFI] = { 0 };

bool can_place(int t){             // 最小间隔为 t 时能否给所有牛都分配到房子
	int num = 1;                   // 分配到房子的牛的数量
	int temp = x[1];
	for(int i = 2; i <= n; i++){
		if(x[i] - temp >= t){
			num++;
			temp = x[i];
			if(num >= m){
				return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x[i]);
	}

	sort(x + 1, x + n + 1);

	int L = 0; int R = x[n] - x[1];
	while(L < R){
		int mid = (L + R + 1) >> 1;
		if(can_place(mid)){
			L = mid;
		}
		else{
			R = mid - 1;
		}
	}
	printf("%d\n", L);
	return 0;
}

/*

约翰有一个有 N 间牛舍的小屋，每个小屋的位置分布在直线的点 x1, ..., xN （0 <= xi <= 10^9） 上
他有 M 头牛 (2 <= M <= N) 他要把牛所在的任意两个屋子之间的距离最长。求最长的最短距离

5 3
1
2
8
4
9

3

*/