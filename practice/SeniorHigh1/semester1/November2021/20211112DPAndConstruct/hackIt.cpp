#include<bits/stdc++.h>
typedef long long ll;
#define Pow18 (ll)1e18

ll a = 0;
ll l = 0; ll r = 0;

int main(){
    scanf("%lld", &a);
    l = a - Pow18 % a * 9 % a * 9 % a;
    r = l + Pow18 - 1;
    printf("%lld %lld\n",l,r);
}