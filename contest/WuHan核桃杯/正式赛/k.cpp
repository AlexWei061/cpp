#include<bits/stdc++.h>
using namespace std;

int t = 0;

int main(){
	cin >> t;
	while(t--){
		int n = 0, m = 0, x = 0, y = 0;
		cin >> n >> m >> x >> y;
		if(min(n, m) == 1) cout << "1\n";
		else cout << min(n, m) + 1 << '\n';
	}
	return 0;
}
