#include<bits/stdc++.h>
using namespace std;

int n = 0; int m = 0;
int   arr[100010] = { 0 };
int     b[100010] = { 0 };          // arr[]的差分数组
int sum_b[100010] = { 0 };          // b[] 的前缀和数组

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < m; i++){
		int L, R, C;
		scanf("%d%d%d", &L, &R, &C);
		b[L-1] += C;
		b[R]   -= C;
	}

	sum_b[0] = b[0];
	for(int i = 1; i < n; i++){
		sum_b[i] = sum_b[i-1] + b[i];
	}

	for(int i = 0; i < n; i++){
		printf("%d ", sum_b[i] + arr[i]);
	}
	printf("\n");

	return 0;
}

/*

给定一个长度为 n 数组 a[], 总共有 m 条指令, 每条指令有 L, R, C 三个数字。表示把 [L, R] 区间内的数组的值
加 C。

输出完成所有指令后的数组

*/