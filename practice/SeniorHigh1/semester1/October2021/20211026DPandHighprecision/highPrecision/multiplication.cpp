#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

struct Tnum{
	int d;
	char num[MAXN];
}a, b;

Tnum mul(Tnum x, Tnum y){
	int a[MAXN] = { 0 }; int b[MAXN] = { 0 };
	int c[MAXN] = { 0 };
	for(int i = 0; i < x.d; i++) a[x.d-i] = x.num[i] - '0';
	for(int i = 0; i < y.d; i++) b[y.d-i] = y.num[i] - '0';
	int temp = 0;
	for(int i = 1; i <= x.d; i++){
		temp = 0;
		for(int j = 1; j <= y.d; j++){
			temp += a[i] * b[j] + c[i+j-1];
			c[i+j-1] = temp % 10; temp/= 10;
		}
	}
	int t = x.d + y.d;
	while(t > 1 and c[t] == 0) t--;
	Tnum z; z.d = t;
	for(int i = t; i >= 1; i--){
		z.num[t-i] = c[i] + '0';
	}
	return z;
}

int main(){
	scanf("%s%s", a.num, b.num);
	a.d = strlen(a.num); b.d = strlen(b.num);
	Tnum c = mul(a, b);
	printf("%s %d\n", c.num, c.d);
	return 0;
}
