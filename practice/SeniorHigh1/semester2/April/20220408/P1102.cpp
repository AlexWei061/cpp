#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200
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
int n = 0; int c = 0;
map<int, int> m;

signed main(){
	n = in; c = in;
	for(int i = 1; i <= n; i++) { a[i] = in; m[a[i]]++; }
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += m[a[i] - c];
	cout << ans << '\n';
	return 0;
}