#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010
#define int long long

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int s[MAXN] = { 0 };
priority_queue<int> q;
int n = 0; int k = 0;

signed main(){
	n = in; k = in; int ans = 0;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) s[i] = (s[i - 1] ^ a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			q.push(s[i] ^ s[j - 1]);
	for(int i = 1; i <= k; i++){
		ans += q.top(); q.pop();
	} cout << ans << '\n';
	return 0;
}