#include<bits/stdc++.h>
using namespace std;

int n = 0;

int Sn(int n){
    int i = 1;
    for(double Snn = 0; Snn <= n; Snn += 1.0 / i, ++i){

    }
    return i - 1;
}

int main(){
    scanf("%d", &n);
    printf("%d\n", Sn(n));
    return 0;
}

/*

已知：Sn= 1 + 1/2 + 1/3 + … + 1/nS 

显然对于任意一个整数 k，当 n 足够大的时候，Sn > k。

现给出一个整数 k，要求计算出一个最小的 n，使得 Sn > k。

1

2

*/