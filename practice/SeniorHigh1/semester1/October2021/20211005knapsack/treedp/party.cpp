#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int r[MAXN] = { 0 };
bool isRoot[MAXN] = { 0 };

int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
//int value[MAXN] = { 0 };
int tot = 0;

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	//value[tot] = weight;
}

int f[MAXN][10] = { 0 };
void dp(int x){
	f[x][0] = 0;
	f[x][1] = r[x];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		dp(y);
		f[x][0] += max(f[y][1], f[y][0]);
		f[x][1] += f[y][0];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		isRoot[i] = true;
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &r[i]);
	}
	for(int i = 1; i < n; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(y, x);
		isRoot[x] = false;
	}

	int root = -1;
	for(int i = 1; i <= n; i++){
		if(isRoot[i]){
			root = i;
			break;
		}
	}
	//printf("root = %d\n", root);

	dp(root);

	printf("%d\n", max(f[root][1], f[root][0]));

	return 0;
}

/*

Ural 大学有 N 个职员，编号为 1～N。他们有从属关系，也就是说他们的关系就像一棵
以校长为根的树，父结点就是子结点的直接上司。每个职员有一个快乐指数。

现在有个周年庆宴会，要求与会职员的快乐指数最大。但是，没有职员愿和直接上司一
起参会。

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0

5

*/