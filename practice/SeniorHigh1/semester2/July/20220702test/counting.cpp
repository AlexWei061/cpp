#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int q = 0;

int main(){
	freopen("counting.in", "r", stdin);
	freopen("counting.out", "w", stdout);
	n = in; q = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	sort(a + 1, a + n + 1);
	while(q--){
		int x = in;
		cout << n - (lower_bound(a + 1, a + n + 1, x) - a) + 1 << '\n';
	}
	return 0;
}
