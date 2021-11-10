#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define endl '\n'

int ans[MAXN] = { 0 };
int n = 0; int k = 0;

int main(){
	scanf("%d%d", &n, &k);
	if(k == 0){
		puts("0");
		for(int i = 1; i <= n; i++) cout << 0 << ' ';
		puts("");
		return 0;
	}
	cout << 1ll * (n + 1) * (n + 1) / 4 << endl;
	for(int i = 1; i < k; i++) ans[i] = 1;
	ans[(n + k + 1 - (k & 1)) / 2] = 1;
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	puts("");
	return 0;
}