#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010
#define MAXM 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int mmap[MAXN][MAXN] = { 0 };
int a[MAXM] = { 0 };

int main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= m; i++) a[i] = in;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) mmap[i][j] = in;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				mmap[i][j] = min(mmap[i][j], mmap[i][k] + mmap[k][j]);
	for(int i = 1; i < m; i++)
		ans += mmap[a[i]][a[i + 1]];
	cout << ans << '\n';
	return 0;
}