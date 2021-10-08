#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int a[MAXN] = { 0 };
int c[10 * MAXN] = { 0 };

inline int lowbit(int x){
	return x & -x;
}

void add(int index, int y){
	for(; index <= n; index += lowbit(index)){
		c[index] += y;
	}
}

int query(int x){              // ²éÑ¯ 1 ~ x µÄºÍ 
	int ans = 0;
	for(; x; x -= lowbit(x)){
		ans += c[x];
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	
	printf("%d\n", query(10));
	
	return 0;
}
