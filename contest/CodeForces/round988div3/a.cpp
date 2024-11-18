#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int t = 0;
int n = 0;
int a[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) c[a[i]]++;
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += c[i] / 2;
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) a[i] = c[i] = 0;
	}
	return 0;
} 
