#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define int long long

int n = 0;
int ans = 0;
int a[MAXN] = { 0 };

signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	ans = a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] >= 0) ans += a[i];
		if(a[i] < 0)  ans -= a[i];
	}
	printf("%lld\n", ans);
	return 0;
} 