#include<bits/stdc++.h>
using namespace std;

#define P 13331
#define MAXN 10010
typedef unsigned long long ull;

char str[MAXN];
ull f[MAXN] = { 0 };
ull p[MAXN] = { 0 };

void prework(int n){
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = P * p[i - 1];
		f[i] = P * f[i - 1] + (str[i] - 'a' + 1);
	}
}

ull queryHash(int l, int r){
	return f[r] - f[l - 1] * p[r - l + 1];
}

int main(){
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	prework(n);
	printf("%llu\n", queryHash(2, 3));
	return 0;
}
