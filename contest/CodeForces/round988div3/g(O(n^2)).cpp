#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int n = 0;
int a[MAXN] = { 0 };
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dp[MAXN] = { 0 };
void bfs(){
	dp[1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(gcd(a[i], a[j]) != 1) dp[j] += dp[i];
	cout << dp[n] << endl;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	bfs();
	return 0;
}
