#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int v[MAXN] = { 0 };              // 合数标记 
void primes(int n){
	memset(v, 0, sizeof(v));
	for(int i = 2; i <= n; i++){
		if(v[i]) continue;
		cout << i << endl;
		for(int j = 1; j <= n / i; j++) v[i * j] = 1;
	}
}

int phi[MAXN] = { 0 };
void euler(int n){
	for(int i = 1; i <= n; i++) phi[i] = i;
	for(int i = 2; i <= n; i++){
		if(phi[i] == i)
			for(int j = i; j <= n; j += i)
				phi[j] = phi[j] / i * (i - 1);
	}
}

int mu[MAXN] = { 0 };
void mobius(int n){
	memset(v, 0, sizeof(v));
	for(int i = 2; i <= n; i++) mu[i] = 1;
	for(int i = 2; i <= n; i++){
		if(v[i]) continue;
		mu[i] = -1;
		for(int j = 2 * i; j <= n; j += i){
			v[j] = 1;
			if((j / i) % i == 0) mu[j] = 0;
			else mu[j] *= -1;
		}
	}
}

int main(){
	primes(100);
	return 0;
}