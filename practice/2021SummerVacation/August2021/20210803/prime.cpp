#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

//质数 : 若一个正整数无法被除了 1 和它本身的任何自然数整除, 则称概数为质数
//质数在自然数集中的分布 : 对于一个足够大的整数 N 不超过 N 的质数大约有 N/ln(N) 个 即每 ln(N) 个数中大约有 1 个质数

int n = 0;

bool isPrime(int n){                            //指数的判定 试除法
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

//质数的筛选 : 给定一个整数 N 求出 1 ~ N 之间所有的质数

int v[MAXN] = { 0 };
void primesEratosthenes(int n){
    /*
    对于任意整数 x， 2x, 3x, 4x ... 都不是质数
    我们从 2 开始依次扫描每个数 x, 把他们的倍数 2x, 3x, 4x ... floor(N/x)*x 做标记
    剩下没做标记的就是质数      runtime complexity : O(nloglogn)
    */
   memset(v, 0, sizeof(v));
   for(int i = 2; i <= n; i++){
       if(v[i]){
           continue;
       }
       printf("%d ", i);
       for(int j = i; j <= n/i; j++){
           v[i * j] = 1;
       }
   }
   printf("\n");
}

int f[MAXN], primes[MAXN];
void primesLinear(int n){
    /*
    Eratosthenes 会重复标记合数 导致时间复杂度增大
    设数组 f 存储每个数的最小质因子 故 if(f[i] == i) --> i为质数
    */

    memset(f, 0, sizeof(f));
    int m = 0;                                                      //质数数量
    for(int i = 2; i <= n; i++){
        if(f[i] == 0){                                              //i 是质数
            f[i] = i;
            primes[++m] = i;
       }
        for(int j = 1; j <= m; j++){                                //给当前的数 i 乘上一个质因子
            if(f[i] < primes[j] or primes[j] > n/i){                //如果 i 有比 primes[j] 小的质因子 或者 超过 n 的范围则停止循环
                break;
            }
            f[i*primes[j]] = primes[j];                             //primes[j]是合数 i*primes[j] 的最小质因子
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
}

/*
质因数分解 :
算术基本定理 : 任何一个大于 1 的正整数都能唯一分解为有限个质数的乘积, 可写作 N = P1^c1 * P2^c2 * ... * Pm^cm
其中 ci 都是正整数, pi 都是质数 且 P1 < P2 < P3 < ... < Pm
*/


//试除法
int p[MAXN], c[MAXN];
void divide(int n){
    /*
    扫描 2 ~ sqrt(N) 之间的每个数 x 若 d 能整除 N, 则从 N 中除掉所有的因子 d, 同时累计除去 d 的个数
    runtime complexity : O(sqrt(n))
    */
   int m = 0;
   for(int i = 2; i <= sqrt(n); i++){
       if(n % i == 0){                                         //有质因子 i
           p[++m] = i;
           c[m] = 0;
           while(n % i == 0){                                  //除去所有因子 i
               n /= i;
               c[m]++;
           }
       }
   }
   if(n > 1){                                                  //n是质数
       p[++m] = n;
       c[m] = 1;
   }
   for(int i = 1; i < m; i++){
       printf("%d^%d * ", p[i], c[i]);
   }
   printf("%d^%d\n", p[m], c[m]);
}

int main(){
    scanf("%d", &n);
    
    printf("%d\n", isPrime(n));
    
    primesEratosthenes(n);
    printf("\n");

    primesLinear(n);
    printf("\n");

    divide(1024);
    return 0;
}