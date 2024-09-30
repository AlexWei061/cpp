#include<bits/stdc++.h>
using namespace std;
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int T = 0;
int n = 0, k = 0;

int main(){
	T = in;
//	freopen("a.out", "w", stdout);
	while(T--){
		n = in, k = in;
		int ans = 0;
		if(k == 1) ans = n;
		else
			while(n) ans += n % k, n /= k;
		cout << ans << '\n';
	}
	return 0;
}
