#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MOD  10

int n = 0; int k = 0;
struct Tmatrix{
    int ma[MAXN][MAXN];
    
    void clear() { memset(ma, 0, sizeof(ma)); }
	void setIdentity(){
		clear();
		for(int i = 1; i <= n; i++) ma[i][i] = 1;
	}
	Tmatrix operator * (const Tmatrix &a) const {
		Tmatrix ans; ans.clear();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++)
					ans.ma[i][j] = (ans.ma[i][j] + ma[i][k] * a.ma[k][j]) % MOD;
		return ans;
	}
	Tmatrix operator + (const Tmatrix &a) const {
		Tmatrix ans; ans.clear();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				ans.ma[i][j] = (ma[i][j] + a.ma[i][j]) % MOD;
		return ans;
	}
}ans, a, b, c;

Tmatrix qp(Tmatrix a, int b){
	Tmatrix ans;
	ans.setIdentity();
	for(; b; b >>= 1){
		if(b & 1) ans = ans * a;
		a = a * a;
	}
	return ans;
}

int main(){
	while(cin >> n >> k and n){
		ans.clear(); a.clear();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a.ma[i][j];
				a.ma[i + n][j] = a.ma[i][j];
			}
			a.ma[n + i][n + i] = 1;
		}
		n <<= 1; ans = qp(a, k); n >>= 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				cout << ans.ma[i + n][j] << ' ';
			puts("");
		}
	}
	return 0;
}