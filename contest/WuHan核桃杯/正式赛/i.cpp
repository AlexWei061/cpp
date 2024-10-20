#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define INFI int(1e9 + 1)

int t = 0;
int n = 0;
int a[MAXN] = { 0 };

int solve(){
	int mmax = 0, mmin = INFI, idx1 = 0, idx2 = 0;
	for(int i = 1; i <= n; i++){
		if(mmax < a[i]) mmax = a[i], idx1 = i;
		if(mmin > a[i]) mmin = a[i], idx2 = i;
	}
	if(idx1 == 1 or idx2 == n) return mmax - mmin;
	else return max(mmax - a[n], max(a[1] - mmin, abs(a[1] - a[n])));
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		cout << solve() << '\n';
	}
	return 0;
} 
