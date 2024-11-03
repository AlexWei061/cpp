#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n = 0, a = 0;
int d[MAXN] = { 0 };

int dfs(int day, int dam, int ang, int pre1, int pre2){
	int ans = 0;
	if(day > n) return dam;
	// op1
	if(pre1 != 1 and pre2 != 1)
		if(pre1 != 4) ans = max(ans, dfs(day + 1, dam + d[day], ang, 1, pre1));
		else ans = max(ans, dfs(day + 1, dam + 2 * d[day], ang, 1, pre1));
	// op2
	if(pre1 != 2 and pre2 != 2) ans = max(ans, dfs(day + 1, dam, ang + a, 2, pre1));
	// op3
	if(pre1 != 3 and pre2 != 3)
		if(pre1 != 4) ans = max(ans, dfs(day + 1, dam + ang, ang, 3, pre1));
		else ans = max(ans, dfs(day + 1, dam + 2 * ang, ang, 3, pre1));
	// op4
	if(pre1 != 4 and pre2 != 4) ans = max(ans, dfs(day + 1, dam, ang, 4, pre1));
	return ans;
}

int main(){
	cin >> n >> a;
	for(int i = 1; i <= n; i++) cin >> d[i];
	cout << dfs(1, 0, 0, 0, 0) << '\n';
	return 0;
} 
