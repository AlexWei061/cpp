#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100 

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];
	int ans = 0;
	for(int i = 2; i <= n; i++) ans = max(ans, b[i]);
	cout << ans << '\n';
	return 0;
}  
 