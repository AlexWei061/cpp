#include<bits/stdc++.h>
using namespace std;

//求(a^b) % p, 1 <= a, b, p <= 10^9
int power(int a, int b, int p){
    int ans = 1 % p;
    for(; b; b >>= 1){
        if(b & 1 == 1){
            ans = (long long)ans * a % p;
        }
        a = (long long)a * a % p;
    }
    return ans;
}

//求(a*b) % p, 1 <= a, b, p <= 10^18
long long mul(long long a, long long b, long long p){
    long long ans = 0;
    for(; b; b >>= 1){
        if(b & 1 == 1){
            ans = (ans + a) % p;
        }
        a = a * 2 % p;
    }
    return ans;
}

int main(){
    int a = 2;
    int b = 3;
    int p = 100000000;
    int ans = mul((long long)a, (long long)b, (long long)p);
    printf("%d^%d = %d\n", a, b, ans);
    return 0;
}