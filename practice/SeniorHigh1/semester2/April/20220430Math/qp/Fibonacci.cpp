#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100100
#define MOD 1000000007

int n = 0;
int f[2] = { 0, 1 };
int a[2][2] = { { 0, 1 }, { 1, 1 } };

void mul(int f[2], int a[2][2]){
	int c[2]; memset(c, 0, sizeof(c));
	for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++)
			c[j] = (c[j] + (long long)f[k] % MOD * a[k][j]) % MOD;
	memcpy(f, c, sizeof(c));
}

void matrixMul(int a[2][2]){
	int c[2][2]; memset(c, 0, sizeof(c));
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
				c[i][j] = (c[i][j] + (long long)a[i][k] % MOD * a[k][j]) % MOD;
	memcpy(a, c, sizeof(c));
}

void quickPower(int n, int f[2], int a[2][2]){
	for(; n; n >>= 1){
		if(n & 1) mul(f, a);
		matrixMul(a);
	}
}

signed main(){
	cin >> n;
	quickPower(n, f, a);
	cout << f[0] << '\n';
	return 0;
}