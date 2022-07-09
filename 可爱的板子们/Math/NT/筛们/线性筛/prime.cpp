#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100001000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int q = 0;
int v[MAXN] = { 0 };
int m = 0;
int pri[MAXN] = { 0 };

//void sieve(int n){
//	memset(v, 0, sizeof(v)); m = 0;
//	for(int i = 2; i <= n; i++){
//		if(v[i] == 0) { v[i] = i; pri[++m] = i; }
//		for(int j = 1; j <= m; j++){
//			if(pri[j] > v[i] or pri[j] > n / i) break;
//			v[i * pri[j]] = pri[j];
//		}
//	}
//}

void sieve(int n){
	memset(v, 0, sizeof(v)); m = 0;
	for(int i = 2; i <= n; i++){
		if(!v[i]) { v[i] = i; pri[++m] = i; }
		for(int j = 1; j <= m; j++){
			if(pri[j] > v[i] or pri[j] > n / i) break;
			v[i * pri[j]] = pri[j];
		}
	}
}

int main(){
	n = in; q = in;
	sieve(n);
	while(q--) cout << pri[in] << '\n';
	return 0;
}
