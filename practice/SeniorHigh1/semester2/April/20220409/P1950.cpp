#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define int long long

int n = 0; int m = 0;
int top;
int s[MAXN] = { 0 };
int sum[MAXN] = { 0 };
int down[MAXN] = { 0 };

signed main(){
	scanf("%lld%lld", &n, &m); int ans = 0;
	for(int i = 1; i <= n; i++){
        top = 0;
		for(int j = 1; j <= m; j++){
			char a; cin >> a;
			if(a == '*') down[j] = i;
			while(top and down[s[top]] < down[j]) top--;
			s[++top] = j;
			sum[top] = sum[top - 1] + (i - down[s[top]]) * (s[top] - s[top - 1]);
			ans += sum[top];
		}
    }
	cout << ans << '\n';
	return 0;
}