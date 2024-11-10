#include<bits/stdc++.h>
using namespace std;

int t = 0;
int n = 0;
string s, r;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s >> r;
		int cnt0 = 0, cnt1 = 0;
		bool f = true;
		for(int i = 0; i < n; i++)
			if(s[i] == '0') cnt0++;
			else cnt1++;
		for(int i = 0; i < n - 1; i++){
			if(cnt1 <= 0 or cnt0 <= 0) f = false;
			if(r[i] == '0') cnt1--;
			else cnt0--;
		}
		if(f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
