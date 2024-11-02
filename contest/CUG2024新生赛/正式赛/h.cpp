#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXC 100
#define mod 1000000007

int n = 0;
int cnt[MAXC] = { 0 };

int cal(int x){
	if(x == 0) return 1;
	int ans = 1;
	for( int i = 1; i <= x; i++) ans = (ans % mod * i % mod) % mod;
	return ans;
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string temp; cin >> temp;
		int len = temp.size();
		cnt[len]++;
	}
	int res = 1;
	for(int i = 1; i <= 26; i++)
		res = (res % mod * cal(cnt[i]) % mod) % mod;
	cout << res << '\n';
	return 0;
} 
