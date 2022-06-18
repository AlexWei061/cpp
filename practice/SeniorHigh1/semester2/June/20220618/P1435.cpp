#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

char a[MAXN] = { 0 };
char b[MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

int main(){
	scanf("%s", a + 1);
	int n = strlen(a + 1);
	for(int i = 1; i <= n; i++) b[i] = a[n - i + 1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			f[i][j] = max(f[i][j], max(f[i -1][j], f[i][j - 1]));
			if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	cout << n - f[n][n] << '\n';
	return 0;
}