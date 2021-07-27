#include<bits/stdc++.h>
using namespace std;

int n = 0;
long long yangHui[105][105] = { 0 };

/*
1  0  0  0  0  0
1  1  0  0  0  0
1  2  1  0  0  0
1  3  3  1  0  0
1  4  6  4  1  0
1  5  10 10 5  1
*/

void generateYangHui(int n){
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			yangHui[i][j] = yangHui[i-1][j] + yangHui[i-1][j-1];
		}
	}
}

int main(){
	yangHui[1][1] = 1;
	scanf("%d", &n);
	generateYangHui(n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			printf("%lld ",yangHui[i][j]);
		}
		printf("\n");
	}
	return 0;
}
