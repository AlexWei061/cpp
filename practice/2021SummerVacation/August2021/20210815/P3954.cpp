#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
    scanf("%d%d%d", &a, &b, &c);
    int ans = (a * 0.2) + (b * 0.3) + (c * 0.5);

    printf("%d\n", ans);
    return 0;
}