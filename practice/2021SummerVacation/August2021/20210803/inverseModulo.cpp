#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b;

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