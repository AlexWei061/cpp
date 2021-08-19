#include<bits/stdc++.h>
using namespace std;

int n = 0;

double Fn(int n){
    double ans = 0;
    ans = (pow((1 + sqrt(5))/2, n) - pow((1 - sqrt(5))/2, n)) / sqrt(5);
    return ans;
}

int main(){
    scanf("%d", &n);
    printf("%.2lf\n", Fn(n));
    return 0;
}