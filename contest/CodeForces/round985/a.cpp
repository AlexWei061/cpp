#include<bits/stdc++.h>
using namespace std;

int t = 0;
int l = 0, r = 0, k = 0;

int solve(int l, int r, int k){
	return r / k - l + 1 > 0 ? r / k - l + 1 : 0;
}

int main(){
	cin >> t;
	while(t--){
		cin >> l >> r >> k;
		cout << solve(l, r, k) << '\n';
	}
	return 0;
} 
