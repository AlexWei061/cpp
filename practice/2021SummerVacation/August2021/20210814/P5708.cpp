#include<bits/stdc++.h>
using namespace std;

double a, b, c;

double cS(double a, double b, double c){
    double p = (a + b + c) / 2.0;
    double ans = sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(){
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%.1lf", cS(a, b, c));
    return 0;
}

/*

已知三角形三边求三角形面积

*/