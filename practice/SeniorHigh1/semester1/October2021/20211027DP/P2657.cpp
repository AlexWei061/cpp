#include<bits/stdc++.h>
using namespace std;
#define int long long

int l = 0; int r = 0; int n = 0;
int num[20] = { 0 }; int f[20][20] = { 0 };

int dfs(int pos, int pre, bool preZ, bool limit){
	if(pos > n) return 1;
	if(!limit and f[pos][pre] != -1) return f[pos][pre];
	int ans = 0;
	int maxdigit = limit ? num[n-pos+1] : 9;
	for(int i = 0; i <= maxdigit; i++){
		if(abs(pre - i) < 2) continue;
		if(preZ and i == 0) ans += dfs(pos+1, -2, true, (limit and i == maxdigit));
		else ans += dfs(pos+1, i, false, (limit and i == maxdigit));
	}
	if(!limit and !preZ) f[pos][pre] = ans;
	return ans;
}

signed main(){
	scanf("%lld%lld", &l, &r);
	memset(f, -1, sizeof(f)); l--;
	while(l){
		num[++n] = l % 10; l /= 10;
	}
	int ansl = dfs(1, -2, 1, 1);
	
	memset(f, -1, sizeof(f));
	n = 0; memset(num, 0, sizeof(num));
	while(r){
		num[++n] = r % 10; r /= 10;
	}
	int ansr = dfs(1, -2, 1, 1);
	printf("%lld\n", ansr - ansl);
	return 0;
}
