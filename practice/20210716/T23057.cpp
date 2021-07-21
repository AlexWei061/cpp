#include<bits/stdc++.h>
using namespace std;

int n = 0;

long long clac(int n){
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		long long temp = 1;
		//printf("when i = %d:\n", i);
		for(int j = i; j > 0; j--){
			//printf("j = %d ", j);
			temp *= j;
			//printf("%lld\n", temp);
		}
		sum += temp;
	}
	return sum;
}

int main(){
	scanf("%d", &n);
	long long sum = clac(n);
	printf("%lld", sum);
	return 0; 
}
