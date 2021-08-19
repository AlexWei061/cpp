#include<bits/stdc++.h>
using namespace std;

int n = 0;

int main(){
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}

/*

计算 1 + 2 + 3 + ... + (n-1) + n 的值，其中正整数 n 不大于 100。由于你没有高斯聪明，所以你不被允许使用等差数列求和公式直接求出答案。

*/