#include<bits/stdc++.h>
using namespace std;

int a = 0, b = 0;

int exgcd(int a, int b, int &x, int &y){        // ax + by = gcd(a, b) --> (x, y)
	if(b == 0){
		x = 1; y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int z = x; 
	x = y; y = z - (a / b) * y;
	return d;
}

// xΪ a ��ģ p �˷���Ԫ 
int inver(int a, int b){                        // ax ��1 (mod b) --> x
	int x = 0; int y = 0;
	exgcd(a, b, x, y);
	return (x % b + b) % b;
}

int main(){
	scanf("%d%d", &a, &b);
	printf("%d\n", inver(a, b));
	return 0;
}
