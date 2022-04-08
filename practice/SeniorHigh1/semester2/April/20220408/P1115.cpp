#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200
#define INFI 1 << 30

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x * f;
}

int n = 0;
int a[MAXN] = { 0 };
int s[MAXN] = { 0 };
int m[MAXN] = { 0 };

int main(){
	n = in; int ans = -INFI;
	for(int i = 1; i <= n; i++) { a[i] = in; s[i] = s[i - 1] + a[i]; }
	for(int i = 1; i <= n; i++) m[i] = min(m[i - 1], s[i]);
	for(int i = 1; i <= n; i++) ans = max(ans, s[i] - m[i - 1]);
	cout << ans << '\n';
	return 0;
}