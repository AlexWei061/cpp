#include<bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define MAXN 100100
#define MAXI (int)1e8
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int inv[MAXI] = { 0 };

void prework(){
	inv[1] = 1;
	for(int i = 2; i <= n; i++){
		inv[i] = (1ll * MOD - MOD / i) * inv[MOD % i] % MOD;
	}
}

int main(){
//	freopen("bogo.in", "r", stdin);
//	freopen("bogo.out", "w", stdout);
	n = in; prework();
	for(int i = 1; i <= n; i++) a[i] = in;
	bool is = true;
	for(int i = 1; i < n; i++)
		if(a[i] > a[i + 1]){
			is = false; break;
		}
	if(is){
		printf("0\n"); return 0;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i++) ans = (1ll * ans * i % MOD) % MOD;
	for(int i = 1; i <= n; i++){
		int temp = 1;
		while(a[i] == a[i + 1]){
			i++; temp++;
		}
		for(int j = 1; j <= temp; j++) ans = (1ll * ans * inv[j] % MOD) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
