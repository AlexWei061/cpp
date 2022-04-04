#include<bits/stdc++.h>
using namespace std;
#define in read()
#define int long long
#define MAXN 500500
#define MOD 999911658

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int x = 0;
int n = 0; int q = 0;
int frac[MAXN] = { 0 };                               // frac[n] = n!
int a[5] = { 0 };                                     // a1 a2 a3 和 a4
int p[5] = { 0, 2, 3, 4679, 35617 };                  // 四个质数 

int qp(int a, int b, int p){                          // 快速幂 
    int ans = 1 % p;
    for(; b; b >>= 1){
        if((b & 1) == 1)
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

void init(int p){
	frac[0] = 1;
	for(int i = 1; i <= p; i++) frac[i] = frac[i - 1] * i % p;
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

void crt(){                                                               // 中国剩余定理 
	for(int i = 1; i <= 4; i++)
		x = (x + a[i] * (MOD / p[i]) % MOD * inv(MOD / p[i], p[i])) % MOD;
}

signed main(){
	n = in; q = in;
	if(q % (MOD + 1) == 0) { cout << 0 << '\n'; return 0; }
	for(int i = 1; i <= 4; i++){
		init(p[i]);
		for(int j = 1; j * j <= n; j++){
			if(n % j == 0){
				a[i] = (a[i] + lucas(n, j, p[i])) % p[i];
				if(j * j != n) a[i] = (a[i] + lucas(n, n / j, p[i])) % p[i];
			}
		}
	}
	crt(); cout << qp(q, x, MOD + 1);
	return 0;
}