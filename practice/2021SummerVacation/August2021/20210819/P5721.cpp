#include<bits/stdc++.h>
using namespace std;

int n = 0;

void print(int n){
    int temp = (n + 1) * n / 2;
    for(int i = 1; i <= temp; i++){
        if(i < 10){
            printf("%d%d", 0, i);
        }
        else{
            printf("%d", i);
        }
        for(int j = n; j >= 0; j--){
            int a = (j + 1) * j / 2;
            if(i == temp - a){
                printf("\n");
                break;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    print(n);
    return 0;   
}

/*

[题目描述]
给出 n (1 ≤ n ≤ 13)，请输出一个直角边长度是 n 的数字直角三角形。所有数字都是 2 位组成的，如果没有 2 位则加上前导 0。

5

0102030405
06070809
101112
1314
15

*/