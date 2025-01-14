#include<bits/stdc++.h>
using namespace std;

int T = 0;
int m, a, b, c;

int main(){
	cin >> T;
	while(T--){
		cin >> m >> a >> b >> c;
		if(a >= m and b >= m) cout << 2 * m << endl;
		else if(a >= m and b < m)
			if(c >= m - b) cout << 2 * m << endl;
			else cout << m + b + c << endl;
		else if(a < m and b >= m)
			if(c >= m - a) cout << 2 * m << endl;
			else cout << m + a + c << endl;
		else if(a < m and b < m)
			if(c >= 2 * m - a - b) cout << 2 * m << endl;
			else cout << a + b + c << endl;
	}
	return 0;
} 
