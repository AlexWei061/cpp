#include<bits/stdc++.h>
using namespace std;

int qread(){
    int w = 1, c, ret;
    while((c = getchar()) > '9' or c < '0'){                  //判断正负数
        w = (c == '-' ? -1 : 1);
    }
    ret = c-'0';
    
    while((c = getchar()) >= '0' and c <= '9'){
        ret = ret * 10 + c - '0';
    }
    return ret * w;
}

int main(){
    printf("%d\n", qread());
    return 0;
}