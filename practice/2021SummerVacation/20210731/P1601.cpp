#include<bits/stdc++.h>
using namespace std;

char a[1010], b[1010];
int  na[1010], nb[1010];
int  sum[1010] = { 0 };

void calcSum(char a[], char b[]){
    unsigned long int lena = strlen(a);
    unsigned long int lenb = strlen(b);

    for(int i = lena-1; i >= 0; i--){
        na[lena-i-1] = a[i] - '0';
    }
    for(int i = lenb-1; i >= 0; i--){
        nb[lenb-i-1] = b[i] - '0';
    }
    
    unsigned long int len = max(lena, lenb);
    for(int i = 0; i < len; i++){
        int temp = na[i] + nb[i];
        sum[i] += temp;
        if(sum[i] >= 10){
            sum[i+1]++;
        }
        sum[i] %= 10;
    }
}


int main(){
    scanf("%s%s", a, b);
    //printf("a.len = %lu b.len = %lu", strlen(a), strlen(b));
    unsigned long int lena = strlen(a);
    unsigned long int lenb = strlen(b);
    unsigned long int len = max(lena, lenb);

    calcSum(a, b);

    /*
    for(int i = 0; i < lena; i++){
        printf("%d", na[i]);
    }
    printf("\n");

    for(int i = 0; i < lenb; i++){
        printf("%d", nb[i]);
    }
    printf("\n");
    */

    if(sum[len] != 0){
        printf("%d", sum[len]);
    }
    for(int i = len-1; i >= 0; i--){
        printf("%d", sum[i]);
    }
    printf("\n");
    
    return 0;
}

/*

高精度 A + B problem

输入两个数 a, b <= 10^500

输出 a 于 b 的和

*/