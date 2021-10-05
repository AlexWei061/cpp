#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
bool isRoot[MAXN] = { 0 };

int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
int tot = 0;

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	//value[tot] = weight;
}

int f[MAXN][MAXN] = { 0 };
void dp(int x){
	f[x][0] = 0;
	f[x][1] = 1;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		dp(y);
		f[x][0] += f[y][1];
		f[x][1] += min(f[y][0], f[y][1]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		isRoot[i] = true;
	}
	for(int i = 0; i < n; i++){
		int x = 0; int m = 0;
		scanf("%d%d", &x, &m);
		for(int j = 0; j < m; j++){
			int y = 0;
			scanf("%d", &y);
			add(x, y);
			isRoot[y] = false;
		}
	}

	int root = -1;
	for(int i = 0; i < n; i++){
		if(isRoot[i]){
			root = i;
			break;
		}
	}

	dp(root);

	printf("%d\n", min(f[root][1], f[root][0]));

	return 0;
}

/*

Bob 喜欢玩电脑游戏，特别是战略游戏。但是他经常无法找到快速玩过游戏的办法。现
在他有个问题。
他要建立一个古城堡，城堡中的路形成一棵树。他要在这棵树的结点上放置最少数目的
士兵，使得这些士兵能了望到所有的路。
注意，某个士兵在一个结点上时，与该结点相连的所有边将都可以被了望到。
请你编一程序，给定一树，帮 Bob 计算出他需要放置最少的士兵.

4
0 1 1
1 2 2 3
2 0
3 0

1

------------------------------------

5
3 3 1 4 2
1 1 0
2 0
0 0
4 0

2

*/