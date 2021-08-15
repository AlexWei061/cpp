#include<bits/stdc++.h>
using namespace std;

#define MAXN 100

/*
一维背包 :
在 2 维背包的计算中需要一个 N * M 的二维数组来存储 dp 的过程
但是有些空间是可以省下来的 比如当 i = 10时 f[5][j]这样的数据就没用了
所以只需要一个 2 * M 的一维数组来存储 dp 过程就可以了

f[j] = max(f[j], f[j- w[i]] + v[i])  w[i] <= j
     = f[j]  w[i] > j

note : 第二层循环要倒序 
我们每次计算f[j] (即f[i][j]) 的时候都会需要f[j-w[i]] (即f[i-1][j-w[i]])的值。
因为j-w[i]比j小，所以如果我们正序计算，那么f[j-w[i]]就已经更新了 (即f[i][j-w[i]])，与状态转移方程不符。
*/

int n = 4, m = 8;
int w[MAXN] = { 0, 2, 3, 4, 5 };
int v[MAXN] = { 0, 1, 2, 5, 6 };
int f[MAXN] = { 0 };

int knapsack(int n, int m, int w[], int v[]){
    for(int i = 0; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            if(w[i] <= j){
                f[j] = max(f[j], f[j-w[i]] + v[i]);
            }
        }
    }
    
    return f[m];
}

int main(){
    printf("%d\n", knapsack(n, m, w, v));
    return 0;
}