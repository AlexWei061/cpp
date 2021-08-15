#include<bits/stdc++.h>
using namespace std;

//RMQ -- range maxinum/mininum query
//ST algorithm
//O(nlog2n)预处理 O(1)查询

/*
f(i, j) 表示arr在[i, i + 2^(j) - 1]上的最大值
就是从i开始的2^j个数的最大
则有
f(i, j) = max( f(i, j-1), f(i+2^(j-1), j-1) )
边界 :
f(i, 0) = arr[i]
*/

int f[100][100] = { 0 };

void STPrework(int arr[], int n){                                   //预处理
    for(int i = 0; i < n; i++){
        f[i][0] = arr[i];
    }
    int t = log(n) / log(2);                                        //t = log2n
    for(int j = 1; j <= t; j++){
        for(int i = 1;i <= n - (1<<j); i++){                        //1 << j = 2^j
            f[i][j] = max(f[i][j-1], f[i - (1 << (j-1))][j-1]);
        }
    }
}

/*
计算k, 使2^k <= R-L+1 <= 2^(k+1), 就是2^k小于区间长度前提下最大的k
从L开始的后2^k个数和以R结尾的前2^k个数一定覆盖了整个[L, R]区间
所以ans = max{f(l, k), f(r-(2^k)+1, k)}
*/
int STQuery(int arr[], int n, int L, int R){
    int k = log(R-L+1) / log(2);
    return max(f[L][k], f[R - (1<<k) + 1][k]);
}

int main(){
    int n = 10;
    int arr[100] = { 0, 123, 45, 23115, 53, 5, 9, 1, 456, 56, 22 };     //下标从1开始
    STPrework(arr, n);
    int mmax = STQuery(arr, n, 3, 5);
    printf("max = %d\n", mmax);
    return 0;
}