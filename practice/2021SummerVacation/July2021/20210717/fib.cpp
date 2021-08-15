#include<bits/stdc++.h>
using namespace std;

int n            =   0  ;
int fiblist[100] = { 0 };

int fib(int n){
	for(int i = 3; i <= n; i++){
		fiblist[i] = fiblist[i-1] + fiblist[i-2];
	}
	return fiblist[n];
}

int main(){
	freopen("fib.in", "r", stdin);
	/freopen("fib.out", "w", stdout);
	scanf("%d", &n);
	fiblist[1] = 1;
	fiblist[2] = 1;
	printf("%d", fib(n));
	return 0;
}
