#include<bits/stdc++.h>
using namespace std;
#define MAXN 3003000
#define int long long

// P3811

int n = 0; int p = 0;
int inv[MAXN] = { 0 };

signed main(){
	scanf("%d%d", &n, &p);
	inv[1] = 1ll;
	printf("%d\n", inv[1]);
	for(int i = 2ll; i <= n; i++){
		inv[i] = (p - p / i) * inv[p % i] % p;
		printf("%d\n", inv[i]);
	}
	return 0;
}