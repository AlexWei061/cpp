#include<bits/stdc++.h>
using namespace std;
#define int long long 

int T = 0;
int n = 0, k = 0;

int solve(int n, int k){
	if(n == 0) return -1;
	int ans = 0;
	for(int i = k; i > 0; i--){
		if(n >= (1LL << i)){
			ans += n / (1LL << i), n %= (1LL << i);
		}
	}
	if(n > 0) return -1;
	else return ans;
}

signed main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		cout << solve(n, k) << '\n';
	}
	return 0;
}
