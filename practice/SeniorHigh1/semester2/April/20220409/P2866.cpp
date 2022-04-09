#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 80080

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
stack<int> s;

signed main(){
	n = in; int ans = 0;
	for(int i = 1; i <= n; i++){
		int h = in;
		while(!s.empty() and s.top() <= h) s.pop();
		ans += s.size(); s.push(h);
	}
	cout << ans << '\n';
	return 0;
}