#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int n = 0;
int a[MAXN] = { 0 };

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = n / 2 + 1; i <= n; i++)
		if(a[i] > ans) ans = a[i];
	cout << ans << '\n';
	return 0;
} 
