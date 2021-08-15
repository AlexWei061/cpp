#include<bits/stdc++.h>
using namespace std;

unsigned long long n = 0;

int main(){
    scanf("%lld", &n);
    unsigned long long ans = n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
    printf("%lld\n", ans);
    return 0;
}