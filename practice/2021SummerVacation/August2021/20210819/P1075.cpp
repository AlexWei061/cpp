#include<bits/stdc++.h>
using namespace std;

int n = 0;

int main(){
    scanf("%d", &n);
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            printf("%d\n", n / i);
        }
    }
    return 0;
}

/*

已知正整数 n 是两个不同的质数的乘积，试求出两者中较大的那个质数。

*/