#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, m, x, y;
int exgcd(ll a, ll m, ll &x, ll &y){
    if(m == 0){
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(m, a%m, x, y);
    int z = x;
    x = y;
    y = z - y * (a/m);
    return d;
}

int gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    scanf("%lld%lld%lld", &a, &b, &m);
    
    int d = exgcd(a, m, x, y);
    if(b % d){
        puts("impossible");
    }
    else{
        printf("%lld\n", x * (b / d) % m);
    }

    return 0;
}

//求解 ax ≡ b (mod m)