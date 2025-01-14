#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int T = 0;
int n, a, b, c;

int main(){
	cin >> T;
	while(T--){
		cin >> n >> a >> b >> c;
		int tot = a + b + c;
		int res = n % tot;
		if(res == 0) res = 0;
		if(1 <= res and res <= a) res = 1; 
		if(a + 1 <= res and res <= a + b) res = 2;
		if(a + b + 1 <= res and res <= a + b + c - 1) res = 3;
		int ans = 3 * (n / tot) + res; 
		cout << ans << endl; 
	}
	return 0;
} 
