#include<bits/stdc++.h>
using namespace std;

double a, h;
double S;

double calcS(double a, double h){
	double S = a * h / 2;
	return S;
}

int main(){
	scanf("%lf%lf", &a, &h);
	S = calcS(a, h);
	printf("%.2lf", S);
	return 0;
}
