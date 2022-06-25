#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INFI 1 << 30

int n = 0;
int a[MAXN] = { 0 };
int s[MAXN] = { 0 };
int f[MAXN][MAXN] =  { 0 };

int main(){
	cin >> n; int maxn = 0, minn = INFI;
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 0, s[i] = s[i - 1] + a[i];
	for(int d = 1; d <= n; d++){
		if(d != 1){
			memset(f, 0x3f, sizeof(f));
			for(int i = 1; i <= n; i++) swap(a[i], a[i - 1]);
			a[n] = a[0], a[0] = 0;
			for(int i = 1; i <= n; i++) f[i][i] = 0, s[i] = s[i - 1] + a[i];
		}
		for(int len = 2; len <= n; len++)
			for(int l = 1; l + len - 1 <= n; l++){
				int r = l + len - 1;
				for(int k = l; k < r; k++)
					f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
				f[l][r] += s[r] - s[l - 1];
			}
		minn = min(minn, f[1][n]);
	}
	cout << minn << '\n';
	for(int i = 1; i <= n; i++) swap(a[i], a[i - 1]);
	a[n] = a[0], a[0] = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 0, s[i] = s[i - 1] + a[i];
	for(int d = 1; d <= n; d++){
		if(d != 1){
			memset(f, 0, sizeof(f));
			for(int i = 1; i <= n; i++) swap(a[i], a[i - 1]);
			a[n] = a[0], a[0] = 0;
			for(int i = 1; i <= n; i++) f[i][i] = 0, s[i] = s[i - 1] + a[i];
		}
		for(int len = 2; len <= n; len++)
			for(int l = 1; l + len - 1 <= n; l++){
				int r = l + len - 1;
				for(int k = l; k < r; k++)
					f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
				f[l][r] += s[r] - s[l - 1];
			}
		maxn = max(maxn, f[1][n]);
	}
	cout << maxn << '\n';
	
	return 0;
}