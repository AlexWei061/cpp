#include<bits/stdc++.h>
using namespace std;
#define int long long

int t = 0;
int n = 0;

signed main(){
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 1) cout << -1 << ' ' << -1 << '\n';
		else cout << n + 1 << ' ' << n * (n + 1) << '\n';
	}
	return 0;
} 
