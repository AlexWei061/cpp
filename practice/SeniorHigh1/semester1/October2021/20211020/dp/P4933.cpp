#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define MAXM 100100
#define MOD 998244353
#define int long long 
// MAXM 开四倍，把负数移到正的来 

int n = 0;
int h[MAXN] = { 0 };
int f[MAXN][MAXM] = { 0 };
int ans = 0; 

signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &h[i]);
	}
	int p = 50005;                             // 移负数 
	for(int i = 1; i <= n; i++){
        ans = (ans + 1) % MOD;                 // 塔总数为 1 的区间 
        for(int j = i - 1; j; j--){
            f[i][h[i] - h[j] + p] = (f[i][h[i] - h[j] + p] + f[j][h[i] - h[j] + p] % MOD + 1) % MOD;
            ans = (ans + f[j][h[i] - h[j] + p] % MOD + 1) % MOD;
        }
    }
    printf("%lld\n", ans);
	return 0;
}
