#include<bits/stdc++.h>
using namespace std;
#define int long long               // 注意要开 long long
#define in read()
#define MAXN 3030
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int m = 0; int n = 0;
int a[MAXN][MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };

signed main(){
	m = in; n = in;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = in;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int mm = INFI; int mx = 0;
			for(int k = 1; k <= m; k++){
				mm = min(mm, a[k][i] + a[k][j]);
				mx = max(mx, a[k][i] + a[k][j]);
			}
			f[i][j] = mm + mx;
		}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans += f[i][j];
	cout << ans << '\n';
	return 0;
}