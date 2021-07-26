#include<bits/stdc++.h>
using namespace std;

/*
lowbit(n)-->非负整数n在二进制表示下最低为的1及其后面所有0构成的数字
eg : n = 10 = (1010)2
lowbit(10) = 2 = (10)2
设正整数n的第k位为1且0~k位都为0
则     ~n的第k位为0且0~k位都为1
则   ~n+1的第k位为1且0~k位都为0且k+1~最高位都与n相反
所以n & (~n + 1)只有第k位为1
lowbit(n) = n & (~n + 1)
~n = -1 - n
lowbit(n) = n & (-n)
*/

int lowbit(int n){
    return (n & (-n));
}

int main(){
    int n = 9;
    int l = lowbit(n);
    printf("lowbit of %d = %d\n", n, l);
    return 0;
}