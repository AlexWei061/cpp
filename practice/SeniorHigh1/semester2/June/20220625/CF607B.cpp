#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

int n = 0;
int a[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 1;
	for(int i = 1; i < n; i++)
		if(a[i] == a[i + 1]) f[i][i + 1] = 1;
		else f[i][i + 1] = 2;
	for(int i = 3; i <= n; i++)
		for(int j = 1; i + j - 1 <= n; j++){
			int l = j, r = i + j - 1;
			if(a[l] == a[r]) f[l][r] = f[l + 1][r - 1];
			for(int k = l; k <= r; k++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
		}
	cout << f[1][n] << '\n';
	return 0;
}