#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int n = 0;
int a[MAXN] = { 0 };
bool vis[MAXN] = { 0 };

double cal(int x, int y){
	if(x < y) swap(x, y);
	double ans = (a[x] - a[y]) / (x - y);
	return ans < 0 ? 0 : ans;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	double ans = 0;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++){
			if(vis[j]) continue;
			if(ans < cal(i, j)) ans = cal(i, j), vis[j] = 1;
		}
	cout << ans << '\n';
	return 0;
} 
