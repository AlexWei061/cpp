#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500

int t = 0;
int frac[MAXN] = { 0 };

int qp(int a, int b, int p){                          // 快速幂 
    int ans = 1 % p;
    for(; b; b >>= 1){
        if((b & 1) == 1)
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

int inv(int a, int p) { return qp(a, p - 2, p); }                         // 求逆元 (质数就是 x^{p-2}) 

int C(int n, int m, int p){                                               // 正常的组合数 
	if(n < m) return 0;
	return (long long)frac[n] * inv(frac[m], p) % p * inv(frac[n - m], p) % p;
}

int lucas(int n, int m, int p){                                           // lucas 求组合数 
	if(n < m) return 0;
	if(!n) return 1;
	return (long long)lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

int main(){
	cin >> t;
	while(t--){
		int n, m, p;
		cin >> n >> m >> p; frac[0] = 1 % p;
		for(int i = 1; i <= p; i++) frac[i] = ((long long)frac[i - 1] * i) % p;
		cout << lucas(n + m, n, p) << '\n';
	}
	return 0;
}