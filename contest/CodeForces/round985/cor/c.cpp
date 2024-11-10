#include<bits/stdc++.h>
using namespace std;
#define MAXN 300300

int t = 0;
int n = 0;
int a[MAXN] = { 0 };
int dp[MAXN][3] = { 0 };

inline int f(int a, int x) { return a + (a < x) - (a > x); }

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			dp[i][0] = f(dp[i - 1][0], a[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][2] = max(f(dp[i - 1][1], a[i]), f(dp[i - 1][2], a[i]));
		}
		cout << max(dp[n][1], dp[n][2]) << '\n';
	}
	return 0;
}
