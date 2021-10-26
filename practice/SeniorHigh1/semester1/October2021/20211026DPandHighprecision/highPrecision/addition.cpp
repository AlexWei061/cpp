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

int main(){
	scanf("%s%s", a.num, b.num);
	a.d = strlen(a.num); b.d = strlen(b.num);
	Tnum c = add(a, b);
	printf("%s %d\n", c.num, c.d);
	return 0;
}
