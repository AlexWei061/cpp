#include<bits/stdc++.h>
using namespace std;
#define int long long 

int t = 0;

int solve(int n, int k){
	n -= (k - 1) * (k - 2) / 2;
	if(n < 0) return 0;
	else return n / k;
}

signed main(){
	cin >> t;
	while(t--){
		int n = 0, k = 0;
		cin >> n >> k;
		cout << solve(n, k) << '\n';
	}
	return 0;
} 
