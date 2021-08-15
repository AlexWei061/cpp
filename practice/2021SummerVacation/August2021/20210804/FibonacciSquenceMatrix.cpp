#include<bits/stdc++.h>
using namespace std;

#define MOD 10000

/*

直接循环递推 Fib(n) = Fib(n-1) + Fib(n-2) 的时间复杂度为 O(n)

设 F(n) 表示一个 1*2 的矩阵, F(n) = [Fib(n) Fib(n+1)]
我们希望通过 F(n-1) 计算出 F(n) : 令 F(n-1) * A = F(n)
A = [0 1]   [Fib(n-1) Fib(n)] * [0 1] = [Fib(n) Fib(n-1)+Fib(n)] = [Fib(n) Fib(n+1)]
    [1 1]                       [1 1]

递推式如上 初始值为 F(0) = [0 1]  目标为 F(n) = F(0) * A^n  用快速幂计算 A^n

O(2^3logn)

*/

int n;
void mul(int f[2], int a[2][2]){
    int c[2];
    memset(c,  0, sizeof(c));
    for(int j = 0; j < 2; j++){
        for(int k = 0; k < 2; k++){
            c[j] = (c[j] + (long long)f[k] * a[k][j]) % MOD;
        }
    }
    memcpy(f, c, sizeof(c));
}

void mulself(int a[2][2]){
    int c[2][2];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] = (c[i][j] + (long long)a[i][k] * a[k][j]) % MOD;
            }
        }
    }
    memcpy(a, c, sizeof(c));
}

int main(){
    while(cin >> n and n != -1){
        int f[2] = { 0, 1 };
        int a[2][2] = { { 0, 1 }, { 1, 1 } };
        for(; n; n >>= 1){
            if(n & 1){
                mul(f, a);
            }
            mulself(a);
        }
        printf("%d\n", f[0]);
    }
    return 0;
}

// 求 Fin(n) mod m (m = 10000 n <= 2 * 10^9)