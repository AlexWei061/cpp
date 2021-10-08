#include<bits/stdc++.h>
using namespace std;

#define P 13331
#define MAXN 100100

/*

P = 13331
M = 1 << 64

H(S + c) = (H(s) * P + value[c]) mod M
H(T) = (H(S+T) - H(s) * P^length(T)) mod M

*/

char s[MAXN];
unsigned long long p[MAXN] = { 0 };                      // p[i] --> P^i
unsigned long long f[MAXN] = { 0 };                      // Hash(S)

void preworkHash(int n){
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1] * P + (s[i] - 'a' + 1);          // hash of 1~i
		p[i] = P * p[i-1];                               // P ^ i
	}
}

unsigned long long Hash(int l, int r){                   // calc hash of l~r
	return f[r] - f[l - 1] * p[r - l + 1];
}

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	preworkHash(n);
	return 0;
}
