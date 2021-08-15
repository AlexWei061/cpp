#include<bits/stdc++.h>
using namespace std;

#define P 10007
#define MAXN 10010

/*

在计算阶乘的过程中, 把 0 <= y <= x <= n 的每个 k! mod p 及其逆元分别保存在两个数组 jc 和 jc_inv 中
则可以在 O(nlogn) 的预处理后, 以 O(1) 的时间回答 0 <= y <= x <= n 的所有组合数 C_{x}^{y} mod p = jc[x] * jc_inv[y] * jc_inv[x-y] mod p 

*/

int fac[MAXN];
int fac_inv[MAXN];

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, x, y);
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
         fac[i] = (fac[i-1]%P * i%P) % P;
         fac_inv[i] = inverseModulo(fac[i], P);
    }
}

//calculate C_{n}^{m} % p
int calcCombinatorialNumber(int n, int m){
    prework(MAXN);
    return (fac[n]%P * fac_inv[m]%P * fac_inv[n-m]%P) % P;
}

int main(){
    /*
    for(int i = 1; i <= 10; i++){
        printf("%d ", fac[i]);
    }
    puts("");

    for(int i = 1; i <= 10; i++){
        printf("%d ", fac_inv[i]);
    }
    puts("");
    */
    int n, m;
    scanf("%d%d", &n, &m);

    printf("%d\n", calcCombinatorialNumber(n, m));

    return 0;
}