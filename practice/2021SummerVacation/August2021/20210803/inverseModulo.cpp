#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b;

/*

ax ≡ 1 (mod b) --> ax mod b = 1 mod b --> (ax-1) mod b = 0
b|(ax-1)   设 ax-1 = kb --> ax - kb = 1 令 y = -k 得 ax + by = 1
gcd(a, b) = 1 --> ax + by = gcd(a, b)
用扩展欧几里得算法求 x, y

*/

int exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, x, y);
    int z = x;
    x = y;
    y = z - y * (a/b);
    return d;
}

int main(){
    scanf("%lld%lld", &a, &b);
    ll x = 0, y = 0;
    exgcd(a, b, x, y);
    printf("%lld\n", (x % b + b) % b);
    return 0;
}

//求关于 x 的同余方程 ax ≡ 1(mod b) 的最小正整数解