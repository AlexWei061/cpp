#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

struct Tnum{
	int d;
	char num[MAXN];
}a, b;

Tnum add(Tnum x, Tnum y){
	int a[MAXN] = { 0 }; int b[MAXN] = { 0 };
	int c[MAXN] = { 0 };
	for(int i = 0; i < x.d; i++) a[x.d-i] = x.num[i] - '0';
	for(int i = 0; i < y.d; i++) b[y.d-i] = y.num[i] - '0';
	int t = max(x.d, y.d); int temp = 0;
	for(int i = 1; i <= t; i++){
		temp += a[i] + b[i]; c[i] = temp % 10; temp /= 10;
	}
	if(temp > 0){
		t++; c[t] = temp;
	}
	Tnum z; z.d = t;
	for(int i = t; i >= 1; i--){
		z.num[t-i] = c[i] + '0';
	}
	return z;
}

Tnum Minus(Tnum x , Tnum y){
	int a[MAXN] = { 0 }; int b[MAXN] = { 0 };
	int c[MAXN] = { 0 };
	for(int i = 0; i < x.d; i++) a[x.d-i] = x.num[i] - '0';
	for(int i = 0; i < y.d; i++) b[y.d-i] = y.num[i] - '0';
	bool isNegative = false; int t = max(x.d, y.d);
	if(x.d < y.d or x.d == y.d and strcmp(x.num, y.num) < 0){
		isNegative = true;
		for(int i = 1; i <= t; i++) swap(a[i], b[i]);
	}
	int temp = 0;
	for(int i = 1; i <= t; i++){
		temp = 10 + a[i] - b[i];
		c[i] = temp % 10;
		a[i+1] += temp / 10 - 1;
	}
	while(t > 1 and c[t] == 0) t--;
	Tnum z; z.d = t;
	if(isNegative){
		for(int i = t; i >= 1; i--) z.num[t-i+1] = c[i] + '0';
		z.num[0] = '-';
	}
	else for(int i = t; i >= 1; i--) z.num[t-i] = c[i] + '0';
	return z;
}

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
	Tnum c = add(a, b);
	printf("%s\n", c.num, c.d);
	return 0;
}
