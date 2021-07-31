#include<bits/stdc++.h>
using namespace std;

struct Num{
	int num;
	bool is_prime;	
};

bool isPrime(int num){
	bool is_prime = true;
	for(int i = 2; i <= sqrt(num); i++){
		//printf("i = %d ", i);
		//printf("mo = %d\n", num%i);
		if(num % i == 0){
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

int n = 0;
Num numlist[10000];

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		numlist[i].num = i;
		numlist[i].is_prime = isPrime(numlist[i].num);
		if(numlist[i].is_prime == true){
			printf("%d ", numlist[i].num);
		}
	}
	return 0;
}
