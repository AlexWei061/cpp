#include<bits/stdc++.h>
using namespace std;
#define MAXN 101 

int t = 0;
int n = 0;
int h[MAXN] = { 0 };

int solve(){
	if(n == 1) return 0;
	int ans = 0, cnt = 1, i = 1;
	while(i < n){
		cnt = 1; bool f = 0;
		while(h[i] == h[i + 1]) f = 1, i++, cnt++;
		ans = max(ans, cnt);
//		if(!f) i++;
		i++;
	}
	ans = n - ans;
	for(int i = 1; i <= 2 * n; i++) h[i] = 0;
	return ans;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> h[i];
		cout << solve() << '\n';
	}
	return 0;
} 
/*
1
10
4 4 4 5 5 5 5 1 1 0
*/
