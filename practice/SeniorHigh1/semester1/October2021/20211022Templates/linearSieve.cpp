#include<bits/stdc++.h>
using namespace std;
#define MAXN int(1e8 + 100)

// P3383

int n = 0;
int q = 0;

int cnt = 0;
bool isprime[MAXN] = { 0 };
int prime[MAXN] = { 0 };

void linearSieve(int n){
	memset(isprime, 1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2; i <= n; i++){
		if(isprime[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt and i * prime[j] <= n; j++){
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0) break;
		}
	}
}

int main(){
	scanf("%d%d", &n, &q);
	linearSieve(n);
	for(int i = 1; i <= q; i++){
		int x = 0;
		scanf("%d", &x);
		printf("%d\n", prime[x]);
	}
	return 0;
}