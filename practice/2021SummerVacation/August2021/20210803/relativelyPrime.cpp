#include<bits/stdc++.h>
using namespace std;

/*

互质 :
定义 任意 a, b 属于 N, 若 gcd(a, b) = 1, 则称 a, b互质

欧拉函数 :
1 ~ N 中与 N 互质的数的个数被称为欧拉函数, 记作 φ(N)
在算术基本定理中 N = p1^c1 * p2^c2 * ... * pm^cm, 则:
φ(N) = N * (p1-1)/p1 * (p2-1)/p2 * ... * (pm-1)/pm = Π_{质数p|N}(1-(1/p))

性质
1. 任意 n > 1, 1 ~ n 中与 n 互质的数的和为 n * φ(n)/2
2. a, b 互质, 则 φ(ab) = φ(a) * φ(b)
积性函数 : 当 a, b 互质时 f(ab)=f(a)f(b)
3. 若 f 是积性函数, 且在算术基本定理中 n = Π_{i=1}^{m}pi^ci, 则 f(n) = Π_{i=1}^{m}f(pi^ci)
4. 设 p 为质数, 若 p|n 且 p^2|n, 则 φ(n) = φ(n/p) * p
5. 设 p 为质数, 若 p|n 且 p^2!|n, 则 φ(n) = φ(n/p) * (p-1)
6. Σ_{d|n}φ(d) = n

*/

int phi(int n){
    int ans = n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            ans = ans / i * (i-1);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){                               //n 是质数
        ans = ans / n * (n-1);
    }
    return ans;
}

int main(){
    printf("%d\n", phi(5));
    return 0;
}