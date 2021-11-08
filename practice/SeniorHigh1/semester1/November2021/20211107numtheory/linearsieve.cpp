#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int v[MAXN] = { 0 };
int prime[MAXN] = { 0 };
int primes(int n){
	memset(v, 0, sizeof(v));
	int cnt = 0;                                                 // 质数的个数
	for(int i = 2; i <= n; i++){
		if(!v[i]){ 
			v[i] = i; prime[++cnt] = i; 
		}
		for(int j = 1; j <= cnt; j++){                           // 枚举所有质数 
			if(prime[j] > v[i] or prime[j] > n / i) break;       // 质数比它大或者超过范围 
			v[i * prime[j]] = prime[j];                          // 更新最小质因子 
		}
	}
	return cnt;
}

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int v[MAXN] = { 0 };
int phi[MAXN] = { 0 };
void euler(int n){
	memset(v, 0, sizeof(v));
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		if(!v[i]){
			v[i] = i; prime[++cnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; j <= cnt; j++){
			if(prime[j] > v[i] or prime[j] > n / i) break;
			v[i *prime[j]] = prime[j];
			if(i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			else phi[i * prime[j]] = phi[i] * prime[j];
		}
	}
}


int main(){
	int num = primes(100);
	for(int i = 1; i <= num; i++){
		cout << prime[i] << endl;
	}
	return 0;
}