#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define P 10007

/*

多项式定理 :
(ax + by)^k = sum_{i=0}^{k} C_{k}^{i} * a^i * b^(k-i) * x^i * y^(k-i)
x^n * y^m 的系数 = C_{k}^{n} * a^n * b^m

*/

int fac[MAXN];
int fac_inv[MAXN];

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y;
    y = z - y * (a/b);
    return d;
}

// nx ≡ 1 (mod p)
int inverseModulo(int n, int p){
    int x; int y;
    exgcd(n, p, x, y);
    return (x % p + p) % p;
}

// runtime complexity : O(nlogn)
void prework(int k){
    fac[0] = 1;
    fac_inv[0] = inverseModulo(fac[0], P);
    for(int i = 1; i <= k; i++){
         fac[i] = (fac[i-1] % P * i % P) % P;
         fac_inv[i] = inverseModulo(fac[i], P);
    }
}

//calculate C_{n}^{m} % p
int calcCombinatorialNumber(int n, int m){
    prework(MAXN);
    return (fac[n] % P * fac_inv[m] % P * fac_inv[n-m] % P) % P;
}

int qpower(int a, int n){
    if(n == 0){
        return 1;
    }
    else if(n % 2 == 1){
        return (a % P * qpower(a, n-1) % P) % P;
    }
    else{
        int temp = qpower(a, n/2);
        return (temp % P * temp % P) % P;
    }
}

int calcCoefficient(int k, int a, int b, int n, int m){
    return (calcCombinatorialNumber(k, n) % P * qpower(a, n) * qpower(b, m)) % P;
}

int main(){
    int k;
    int a; int b;
    int n; int m;
    scanf("%d%d%d%d%d", &k, &a, &b, &n, &m);
    printf("%d\n", calcCoefficient(k, a, b, n, m));
    return 0;
}


/*

给定 (ax + by)^k, 求出多项式展开后 n^n*y^m 的系数, 对 10007 取模。
0 <= n, m <= k <= 10000, n + m = k, 0 <= a, b <= 10^6

*/