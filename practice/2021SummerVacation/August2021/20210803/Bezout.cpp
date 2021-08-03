#include<bits/stdc++.h>
using namespace std;

/*

扩展欧几里得算法
Bezout 定理 :
对于 ∃ 整数 a, b, 存在一个整数 x, y, 满足 ax + by = gcd(a, b)

在欧几里得算法的最后一步, 即 b = 0时, 显然有 x = 1, y = 0, 使得 a * 1 + 0 * 0 = gcd(a, 0)
若 b > 0 , 则 gcd(a, b) = gcd(b, a mod b) 假设存在一对整数 x, y, 满足 b * x + (a mod b) * y = gcd(b, a mod b)
因为 bx + (a mod b)y = bx + (a - b[a/b])y = ay + b(x - [a/b]y) = gcd(b, a mod b) = gcd(a, b)
所以令 x' = y, y' = x - [a/b]y, 就得到了 ax' + by' = gcd(a, b)
证毕

*/

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, x, y);
    int z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}

int main(){
    int x, y;
    printf("%d\n", exgcd(12, 15, x, y));
    
    return 0;
}