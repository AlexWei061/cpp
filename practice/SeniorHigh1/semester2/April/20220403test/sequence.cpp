#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x ;
}

int n = 0;
int l = 0; int r = 0;
int a[MAXN] = { 0 };
int s[MAXN] = { 0 };

signed main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = in; l = in; r = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	double ans = 0;
	for(int len = l; len <= r; len++){
		for(int R = n; R - len + 1 >= 1; R--){
			int L = R - len + 1;
			ans = max(ans, double(s[R] - s[L - 1]) / double(R - L + 1));
		}
	}
	printf("%.4lf\n", ans);
	return 0;
}
