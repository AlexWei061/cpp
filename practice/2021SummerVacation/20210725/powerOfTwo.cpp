#include<bits/stdc++.h>
using namespace std;

/*
runtime complexity : O(log2n)
bool isPowerOfTwo(int n){
    while(n % 2 == 0){
        n /= 2;
    }
    if(n == 1){
        return true;
    }
    return false;  
}
*/

/*
2^n次方化成2进制后都是100...0(1后面n个0)
(2^n)-1化成2进制后都是011...1(0后面n个1)
所以(2^n) & (2^n-1) = 0
所以若数字m & (m-1) = 0, m就可以写成2^n的形式
*/

//runtime complexity : O(1)
bool isPowerOfTwo(int n){
    if(n <= 0){
        return false;
    }
    else if(n == 1){
        return true;
    }
    else if((n & (n-1)) == 0){          // &的运算级别比==低所以要再加一个括号
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n = 256;
    printf("%d\n", isPowerOfTwo(n));
    return 0;
}

/*
Given an integer, write a function to determine if it is a power of two
*/
