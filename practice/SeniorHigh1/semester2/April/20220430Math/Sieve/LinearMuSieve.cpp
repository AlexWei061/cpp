#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010000

int n = 0; int m = 0;
int pri[MAXN] = { 0 };
int v[MAXN] = { 0 };
int mu[MAXN] = { 0 };

void sieve(int n){
	mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!v[i]) { pri[++m] = i; mu[i] = -1; }
		for(int j = 1; j <= m; j++){
			if(pri[j] > n / i) break;
			v[pri[j] * i] = pri[j];
			if(i % pri[j] == 0){
				mu[i * pri[j]] = 0;
				break;
			}
			mu[i * pri[j]] = -mu[i];
		}
	}
}

int main(){
	cin >> n;
	sieve(n);
	for(int i = 1; i <= n; i++) cout << mu[i] << ' '; puts("");
	return 0;
}