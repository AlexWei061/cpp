#include<bits/stdc++.h>
using namespace std;

int T = 0;
int n = 0;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 0;
		if(n == 1) ans = 1;
		else if(n == 2) ans = 2;
		else if(n == 3) ans = 2;
		else {
			int l = 1, r = 30;
			while(l < r){
				int mid = l + r >> 1;
				int val = 3 * pow(2, mid) - 2;
				if(n > val) l = mid + 1;
				else r = mid;
			}
			ans = l + 1;
		}
		cout << ans << endl;
	}
	return 0;
} 
