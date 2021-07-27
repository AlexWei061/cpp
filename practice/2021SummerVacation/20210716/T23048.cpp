#include<bits/stdc++.h>
using namespace std;

int n = 0;

int ClacSum(int n){
	int sum = 0;
	for(int i = 2; i <= n; i+=2){
		sum += i;
	}
	return sum;
} 

int main(){
	scanf("%d", &n);
	int sum = ClacSum(n);
	printf("%d\n", sum);
	return 0;
}
