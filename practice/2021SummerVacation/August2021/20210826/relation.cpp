#include<bits/stdc++.h>
using namespace std;

#define MAXN (int)1e6 + 100

int n = 0, m = 0;
int q = 0;

int parent[MAXN] = { 0 };
int  rrank[MAXN] = { 0 };

void initialize(){
	for(int i = 0; i < n; i++){
		parent[i] = -1;
		rrank[i]  =  0;
	}
}

int findRoot(int x){
	while(parent[x] != -1){
		x = parent[x];
	}
	return x;
}

void unionVertices(int x, int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if(xRoot == yRoot){
		return;
	}
	else{
		if(rrank[xRoot] > rrank[yRoot]){
			parent[yRoot] = xRoot;
		}
		else if(rrank[xRoot] < rrank[yRoot]){
			parent[xRoot] = yRoot;
		}
		else{
			parent[xRoot] = yRoot;
			rrank[yRoot]++;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	initialize();
	for(int i = 1; i <= m; i++){
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		unionVertices(x, y);
	}

	scanf("%d", &q);
	
	for(int i = 1; i <= q; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		int xRoot = findRoot(x);
		int yRoot = findRoot(y);
		if(xRoot == yRoot){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}

/*

[题目描述]
或许你并不知道，你的某个朋友是你的亲戚。他可能是你的曾祖父的外公的女婿的外甥女的表姐的孙子。如果能得到完整的家谱，
判断两个人是否亲戚应该是可行的，但如果两个人的最近公共祖先与他们相隔好几代，使得家谱十分庞大，那么检验亲戚关系实非人力所能及。
在这种情况下，最好的帮手就是计算机。为了将问题简化，你将得到一些亲戚关系的信息，如 Marry 和 Tom 是亲戚，Tom 和 Ben是亲戚，等等。从这些信息中，
你可以推出 Marry 和 Ben 是亲戚。请写一个程序，对于我们的关于亲戚关系的提问，以最快的速度给出答案。

10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9

Yes
No
Yes

*/