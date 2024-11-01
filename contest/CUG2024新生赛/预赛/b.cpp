#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define in read()
#define mod 1000000007

int t = 0;
int a = 0, b = 0;

int qp(int a, int b){
	if(b == 0) return 1;
	int ans = 1;
	while(b){
//		printf("a = %d b = %d\n", a, b);
		if(b & 1) ans = (ans % mod * a % mod) % mod;
		a = (a % mod * a % mod) % mod; b >>= 1;
//		if(b & 1) ans *= a;
//		a *= a, b >>= 1;
	} 
	return ans;
}

signed main(){
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << qp(a, b) << '\n';	
	}
	return 0;
} 
