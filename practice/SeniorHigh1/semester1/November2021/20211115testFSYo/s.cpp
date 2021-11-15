#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define endl '\n'
typedef long long ll; 

int n = 0;
int type = 0;

int f[MAXN] = { 0 };
int ans[MAXN][MAXN] = { 0 };

int main(){
	scanf("%d%d", &n, &type);
	if(!type){
		if(n <= 1000){
			f[2] = 2; f[4] = 8; f[6] = 16;
			for(int i = 8; i <= n; i += 2) f[i] = f[i-6] + 4 * (i - 2);
			cout << f[n] << endl;	
		}
		else{
			ll ans = 0;
			if((n - 2) % 6 == 0) ans = 2 + (1ll * n * n + 1ll * 2 * n - 8) / 3;
			else if((n - 4) % 6 == 0) ans = 8 + (1ll * n * n + 1ll * 2 * n - 24) / 3;
			else ans = 16 + (1ll * n * n + 1ll * 2 * n - 48) / 3;
			cout << ans << endl;
		}
		return 0;
	}
	else{
		f[2] = 2; f[4] = 8; f[6] = 16;
		for(int i = 8; i <= n; i += 2) f[i] = f[i-6] + 4 * (i - 2);
		cout << f[n] << endl;
		if(n == 2) ans[1][1] = ans[2][2] = 1;
		else if(n == 4){
			ans[1][1] = ans[1][2] = ans[1][4] = 1;
			ans[2][4] = ans[3][1] = 1;
			ans[4][1] = ans[4][3] = ans[4][4] = 1;
		}
		else if(n == 6){
			ans[1][1] = ans[1][2] = ans[1][4] = ans[1][6] = 1;
			ans[2][4] = ans[2][6] = ans[5][1] = ans[5][3] = 1;
			ans[3][1] = ans[3][2] = ans[4][5] = ans[4][6] = 1;
			ans[6][1] = ans[6][3] = ans[6][5] = ans[6][6] = 1;
		}
		else{
			for(int x = 1; x <= n / 2; x += 3){
				for(int i = x; i <= n - x - 1 ; i += 2){
					ans[i][x] = ans[i][x+1] = 1;
					ans[n-x+1][i] = ans[n-x][i] = 1;
				}
				for(int i = x + 3; i <= n - x + 1 ; i += 2){
					ans[x][i] = ans[x+1][i] = 1;
					ans[i][n-x+1] = ans[i][n-x] = 1;
				}
			}
			if((n - 8) % 6 == 0) ans[n/2][n/2] = ans[n/2+1][n/2+1] = 1;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << ans[i][j] << ' ';
			}
			puts("");
		}
	}
	return 0;
}