#include<bits/stdc++.h>
using namespace std;

int  n = 0;
char x[100];

int a[100] = { 0 };
int toDecimal(char* x, int n){
	int len = (int)strlen(x);
	int ans = 0;
	for(int i = 0; i < len; i++){
		if(x[i] >= '0' and x[i] <= '9'){
			a[i] = x[i] - '0';
		}
		if(x[i] >= 'A' and x[i] <= 'F'){
			a[i] = x[i] + 10 - 'A';
		}
	}

	ans = a[len-1];
	int mul = 1;
	for(int i = len - 2; i >= 0; i--){
		mul *= n;
		ans += a[i] * mul;
	}

	return ans;
}

int main(){
	scanf("%s%d", x, &n);

	printf("%d\n", toDecimal(x, n));
	return 0;
}

/*

将 n 进制数 x 转化为 10 进制数

*/