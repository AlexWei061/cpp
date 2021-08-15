#include<bits/stdc++.h>
using namespace std;

int n = 0;

bool ALike(int x){
    if(x % 2 == 0 and (x > 4 and x <= 12)){
        return true;
    }
    return false;
}

bool UimLike(int x){
    if(x % 2 == 0 or (x > 4 and x <= 12)){
        return true;
    }
    return false;
}

bool BaYongLike(int x){
    if(x % 2 == 0 xor (x > 4 and x <= 12)){
        return true;
    }
    return false;
}

bool ZhengMeiLike(int x){
    if(!(x % 2 == 0) and !(x > 4 and x <= 12)){
        return true;
    }
    return false;
}

int main(){
    scanf("%d", &n);
    printf("%d %d %d %d\n", ALike(n), UimLike(n), BaYongLike(n), ZhengMeiLike(n));
    return 0;
}

/*

[题目描述]
一些数字可能拥有以下的性质：

性质 1：是偶数；
性质 2：大于 4 且不大于 12。

小 A 喜欢这两个性质同时成立的数字；Uim 喜欢这至少符合其中一种性质的数字；八尾勇喜欢刚好有符合其中一个性质的数字；正妹喜欢不符合这两个性质的数字。

12
1 1 0 0

*/