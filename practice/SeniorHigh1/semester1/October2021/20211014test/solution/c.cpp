#include<bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 998244353

inline int read(){
	int s = 0, k = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')k = -1; c = getchar();
	}
	while(isdigit(c)){
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * k;
}

int n = 0, m = 0;
int f[205][3500] = { 0 };

int pw(int a, int b){                  // ¿ìËÙÃİ 
	int ans = 1;
	while(b){
		if(b & 1){
			ans *= a;
			ans %= MOD;	
		}
		a *= a; a %= MOD;
		b >>= 1;
	}
	return ans;
}

int C(int cnt){
	f[0][0] = 1;
	for(int i = 1; i <= 2 * m; i++){
		for(int j = 0; j <= cnt * m; j++) f[i][j] = 0;
		for(int j = 0; j <= cnt; j++){
			for(int k = cnt * m; k >= j; k--){
				f[i][k] += f[i - 1][k - j];
				f[i][k] %= MOD;
			}
		}
	}
	return f[2*m][cnt*m];
}

signed main(){
	n = read(); m = read();
	int ans1 = 1, ans2 = 1, len = sqrt(n);
	for(int i = 2; i <= len; i++){
		if(n % i == 0){
			int cnt = 0;
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			ans1 *= C(cnt); ans1 %= MOD;
			ans2 *= (cnt + 1); ans2 %= MOD;
		}
	}
	if(n != 1){
		ans2 *= 2; ans1 *= C(1); 
		ans1 %= MOD; ans2 %= MOD;
	}
	cout << (((pw(ans2, 2 * m) - ans1) % MOD + MOD) % MOD * pw(2, MOD - 2) % MOD + ans1) % MOD << endl;
}
