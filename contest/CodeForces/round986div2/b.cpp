#include<bits/stdc++.h>
using namespace std;
#define int long long

int t = 0;
int n = 0;
int b = 0, c = 0;

signed main(){
	cin >> t;
	while(t--){
		cin >> n >> b >> c;               // a[i] = b(i - 1) + c
		if(b == 0)
			if(c > n - 1) cout << n << '\n';
			else if(c < n - 2) cout << -1 << '\n';
			else cout << n - 1 << '\n'; 
		else{
			if(c > n - 1) cout << n << '\n';
			else cout << n - max(0ll, 1 + (n - c - 1) / b) << '\n';
		}
	}
	return 0;
} 
// 10 1435145 164134613461346
