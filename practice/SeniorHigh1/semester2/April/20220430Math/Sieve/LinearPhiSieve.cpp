#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 10001000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int pri[MAXN] = { 0 };
int phi[MAXN] = { 0 };
int v[MAXN] = { 0 };

void sieve(int n){
	phi[1] = 1;
	memset(v, 0, sizeof(v)); m = 0;
	for(int i = 2; i <= n; i++){
		if(!v[i]) { pri[++m] = i; phi[i] = i - 1; }
		for(int j = 1; j <= m; j++){
			if(pri[j] > n / i) break;
			v[i * pri[j]] = pri[j];
			if(i % pri[j] == 0){
				phi[i * pri[j]] = phi[i] * pri[j];
				break; 
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}

int main(){
	n = in;
	sieve(n);
	for(int i = 1; i <= n; i++) cout << phi[i] << ' ';
	puts("");
	return 0;
}