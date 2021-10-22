#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500

// P3374

int n = 0; int m = 0;
int a[MAXN] = { 0 };
int c[4 * MAXN] = { 0 };

inline int lowbit(int x){
	return x & -x;
}

void add(int idx, int val){
	for(; idx <= n; idx += lowbit(idx)){
		c[idx] += val;
	}
}

int query(int x){
	int ans = 0;
	for(; x; x -= lowbit(x)){
		ans += c[x];
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	for(int i = 1; i <= m; i++){
		int op = 0; int x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1){
			add(x, y);
		}
		else if(op == 2){
			printf("%d\n", query(y) - query(x-1));
		}
	}
	return 0;
}