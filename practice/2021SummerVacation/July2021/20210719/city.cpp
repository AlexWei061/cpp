#include<bits/stdc++.h>
using namespace std;

int N = 0;
int X = 0;
int cityPosition[100001] = { 0 };

void work(int n, int x, int list[]){                //预处理成gcd需要的数据 
	for(int i = 1; i <= n; i++){
		list[i] = abs(list[i] - x);
	}
}

//int m, n;

int calcGcd(int m , int n){
	int gcd = 0;
	int temp = m % n;
	if(temp == 0){
		gcd = n;
	}
	else{
		gcd = calcGcd(n, m%n);
	}
	return gcd;
}

int main(){
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	scanf("%d%d", &N, &X);
	for(int i = 1; i <= N; i++){
		scanf("%d", &cityPosition[i]); 
	}
	
	work(N, X, cityPosition);
	
	/*
	for(int i = 1; i <= N; i++){
		printf("%d ", cityPosition[i]); 
	}
	*/
	
	//gcd(a, b, c) = gcd( gcd(a, b) , c ) 
	int gcd = cityPosition[1];
	for(int i = 1; i <= N; i++){ 
		gcd = calcGcd(gcd, cityPosition[i]);
	}
	
	
	printf("%d", gcd);
	/*
	scanf("%d%d", &m, &n);
	int gcd = calcGcd(m, n);
	printf("%d and %d 's gcd = %d\n", m, n, gcd);
	*/
	return 0;
}
