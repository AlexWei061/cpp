#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001000

inline int read(){
	int x = 0; char c= getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	n = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) c[i] = a[i] - a[i - 1];
	sort(c + 1, c + n + 1);
	cout << c[n] << '\n';
	return 0;
}