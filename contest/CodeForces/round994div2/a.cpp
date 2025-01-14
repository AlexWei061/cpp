#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int T = 0;
int n = 0;
int a[MAXN] = { 0 };

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		bool all0 = 1;
		int l = 1, r = n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] != 0) all0 = 0;
		}
		if(all0) cout << 0 << endl;
		else{
			while(a[l] == 0) l++;
			while(a[r] == 0) r--;
			int cnt = 0;
			for(int i = l; i <= r; i++) if(a[i] == 0) cnt++;
			if(cnt == 0) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	return 0;
} 
