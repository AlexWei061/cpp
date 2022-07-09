#include<bits/stdc++.h>
using namespace std;

// P1226

int a = 0; int b = 0; int p = 0;

int quickPower(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1){
		if(b & 1) ans = (long long)a * ans % p;
		a = (long long)a * a % p;
	}
	return ans;
}

int main(){
	scanf("%d%d%d", &a, &b, &p);
	printf("%d^%d mod %d=%d\n", a, b, p, quickPower(a, b, p));
	return 0;
}
