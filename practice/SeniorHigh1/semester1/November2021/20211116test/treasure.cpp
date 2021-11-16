#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 101
#define MAXK 100100
typedef long long ll;

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

struct BIT{
	int c[MAXM];
	
	inline int lowbit(int x){
		return x & -x;
	}
	void add(int x, int v){
		if(!x) c[0] += v;
		for(; x < MAXM and x; x += lowbit(x))
			c[x] += v;
	}
	int query(int x){
		int ans = 0;
		for(; x; x -= lowbit(x)) ans += c[x];
		return ans + c[0];
	}
}s[MAXK * 3];

int k = 0;
int n = 0; int m = 0;
int cnt = 0; ll ans = 0;
int f[MAXN][MAXM] = { 0 };
int g[MAXN][MAXM] = { 0 };
int a[MAXN][MAXM] = { 0 };

int main(){
	n = in; m = in; k = in;
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for(int j = 1; j <= m; j++)
			if(getchar() == '$'){ f[i][j]++; g[i][j]++; cnt++; }
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
	for(int i = n; i; i--)
		for(int j = n; j; j--)
			g[i][j] += g[i+1][j] + g[i][j+1] - g[i+1][j+1];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			a[i][j] = f[i][j] - g[i+1][j+1];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++)
			s[a[i-1][j] + 2*cnt].add(j, 1);
		for(int j = 1; j <= m; j++)	
			ans += 1ll * s[a[i][j] - k + 2*cnt].query(j-1);
	}
	cout << ans << endl;
	return 0;
}