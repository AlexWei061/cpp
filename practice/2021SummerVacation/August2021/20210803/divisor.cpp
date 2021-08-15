#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

//求 N 的正约数集合 -- 试除法
int factor[MAXN];
void divisor1(int n){
    int m = 0;                                        //约数的总数
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            factor[++m] = i;
            if(i != n/i){
                factor[++m] = n/i;
            }
        }
    }
    sort(factor+1, factor+m+1);

    for(int i = 1; i <= m; i++){
        printf("%d ", factor[i]);
    }
    printf("\n");
}

//倍数法
vector<int> fac[MAXN];
void divisor2(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n/i; j++){
            fac[i*j].push_back(i);
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < fac[i].size(); j++){
            printf("%d ", fac[i][j]);
        }
        printf("\n");
    }
    */
   for(int i = 0; i < fac[n].size(); i++){
       printf("%d ", fac[n][i]);
   }
   printf("\n");
}

//最大公约数 -- 欧几里得算法
/*
任意a, b 属于 N, b != 0, gcd(a, b) = gcd(b, a mod b)
证明 :
若 a < b 则 gcd(b, a mod b) = gcd(b, a) = gcd(a, b)
若 a >= b 不妨设 a = q * b + r 其中 0 <= r <= b 显然 r = a mod b. 对于 a, b 的任意公约数 d, 因为 d|a, d|q*b 故 d|(a-qb)
即 d|r, 因此, d 也是b, r 的公约数. 反之亦成立
所以 a, b 的公约数集与 b, r 的公约数集相同. 即 a, b 的公约数集与 b, a mod b 的公约数集相同, 故 gcd(a, b) = gcd(b, a mod b)
证毕
*/
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    divisor1(60);

    divisor2(60);

    return 0;
}