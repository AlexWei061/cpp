#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int T = 0;
int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) { cin >> b[i]; b[i - 1] = b[i]; } b[n] = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++) 
			if(a[i] - b[i] > 0) ans += (a[i] - b[i]);
		cout << ans << endl; 
	}
	return 0;
} 
