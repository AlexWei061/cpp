#include<bits/stdc++.h>
using namespace std;

char a[2020],  b[2020];
int na[2020], nb[2020];
int f[5050][5050];
int product[5050];

void calcMul(char a[], char b[]){
    unsigned long int lena = strlen(a);
    unsigned long int lenb = strlen(b);
    
    for(int i = 0; i < lena; i++){
        na[lena-i-1] = a[i] - '0';
    }
    for(int i = 0; i < lenb; i++){
        nb[lenb-i-1] = b[i] - '0';
    }

    //unsigned long int len = min(lena, lenb);
    for(int i = 0; i < lena; i++){
        for(int j = 0; j < lenb; j++){
            f[i][j+i] = na[i] * nb[j];
        }
    }
    
    for(int i = 0; i <lena; i++){
        for(int j = 0; j < lena + lenb; j++){
            int temp = f[i][j] - (f[i][j] % 10);
            f[i][j] %= 10;
            f[i][j+1] += temp / 10;
        }
    }

    for(int i = 0; i < lena + lenb; i++){
        for(int j = 0; j < lena; j++){
            product[i] += f[j][i];
        }
    }

    for(int i = 0; i < lena + lenb; i++){
        int temp = product[i] - (product[i] % 10);
        product[i] %= 10;
        product[i+1] += temp / 10;
    }
    
}

int main(){
    scanf("%s%s", a, b);
    unsigned long int lena = strlen(a);
    unsigned long int lenb = strlen(b);

    calcMul(a, b);

    /*
    for(int i = 0; i < lena; i++){
        printf("%d", na[i]);
    }
    printf("\n");

    for(int i = 0; i < lenb; i++){
        printf("%d", nb[i]);
    }
    printf("\n");

    for(int i = 0; i < lena; i++){
        for(int j = 0; j < lena + lenb; j++){
            printf("%-3d ", f[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < lena + lenb; i++){
        printf("%-3d", product[i]);
    }
    printf("\n");
    */

    int i = lena + lenb;
    while(product[i] == 0 and i >= 1){
        i--;
    }
    for(i; i >= 0; i--){
        printf("%d", product[i]);
    }
    printf("\n");

    return 0;
}

/*

高精度 a * b problem

*/