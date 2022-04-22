#include<bits/stdc++.h>
using namespace std;
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	n = in; int ans = 0;
	for(int i = 1; i <= n; i++) { int x = in; q.push(x); }
	while(q.size() >= 2){
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
//		printf("x = %d y = %d\n", x, y);
		ans += x + y; q.push(x + y);
	}
	cout << ans << '\n';
	return 0;
}