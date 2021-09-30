#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001000

int n = 0;
int a[MAXN] = { 0 };
//int c[MAXN] = { 0 };

/*
int lowbit(int x){
	return x & ~x;
}

void add(int index, int val){
	for(; index <= n; index += lowbit(index)){
		c[index] += val;
	}
}

int query(int x){
	int ans = 0;
	for(; x; x -= lowbit(x)){
		ans += c[x];
	}
	return ans;
}
*/

long long ans=0;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		//add(i, a[i]);
	}

	for(int i = 2; i <= n; i++){
	    if(a[i] > a[i-1]){
	    	ans += a[i] - a[i-1];
	   	}
	}
	cout << ans + a[1];
	
	return 0;
}

/*

春春是一名道路工程师，负责铺设一条长度为 n 的道路。

铺设道路的主要工作是填平下陷的地表。整段道路可以看作是 n 块首尾相连的区域，一开始，第 i 块区域下陷的深度为 d_i。

春春每天可以选择一段连续区间[L,R] ，填充这段区间中的每块区域，让其下陷深度减少 1。在选择区间时，需要保证，区间内的每块区域在填充前下陷深度均不为 0 。

春春希望你能帮他设计一种方案，可以在最短的时间内将整段道路的下陷深度都变为 0 

6   
4 3 2 5 3 5 

9

*/