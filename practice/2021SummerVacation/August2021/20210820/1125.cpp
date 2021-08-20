#include<bits/stdc++.h>
using namespace std;

#define INFI INT_MAX

char str[101];
int  way[30] = { 0 };
int maxn = 0;
int minn = INFI;

bool isPrime(int x){
    if(x == 0){
        return false;
    }
    if(x == 1){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int index = str[i] - 'a';
        way[index]++;
    }
    for(int i = 0; i < 26; i++){
        if(way[i] != 0){
            maxn = max(maxn, way[i]);
            minn = min(minn, way[i]);
        }
    }

    //printf("maxn = %d minn = %d\n", maxn, minn);

    int num = maxn - minn;

    if(isPrime(num)){
        printf("Lucky Word\n%d\n", num);
    }
    else{
        printf("No Answer\n%d\n", 0);
    }

    return 0;
}