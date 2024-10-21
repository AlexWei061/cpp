#include<bits/stdc++.h>
using namespace std;
#define int long long

int t = 0;

signed main(){
	cin >> t;
	while(t--){
		int n = 0, m = 0, x = 0, y = 0;
		cin >> n >> m >> x >> y;
		int temp = n < m ? n : m;
		if(n == 1 and m == 1) cout << 0 << '\n';
		else if(temp == 1) cout << 1 << '\n';
		else cout << temp + 1 << '\n';
	}
	return 0;
}
