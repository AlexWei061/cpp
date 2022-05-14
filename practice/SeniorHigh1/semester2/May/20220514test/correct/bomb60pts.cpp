#include<bits/stdc++.h>
using namespace std;
#define db double
#define in read()
#define MAXN 1010
#define INFI 1 << 30
#define ESP 1e-6
#define max(a, b) (a - b >= ESP ? a : b)
#define min(a, b) (a - b >= ESP ? b : a)

inline db read(){
	db x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
db a[MAXN] = { 0 };
db f[MAXN] = { 0 };
db g[MAXN] = { 0 };

int main(){
	freopen("a.in", "r", stdin);
	n = in; db ans = INFI;
	for(int i = 1; i <= n; i++) a[i] = in;
//	for(int i = 1; i <= n; i++) cout << a[i] << ' '; puts("");
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		db temp = INFI;
		for(int j = 1; j < i; j++) temp = min(temp, max(3 * f[j] / 2, a[i] - a[j]));
		f[i] = temp;
	}
	for(int i = n - 1; i >= 1; i--){
		db temp = INFI;
		for(int j = i + 1; j <= n; j++) temp = min(temp, max(3 * g[j] / 2, a[j] - a[i]));
		g[i] = temp;
	}
//	for(int i = 1; i <= n; i++) cout << f[i] << ' '; puts("");
//	for(int i = 1; i <= n; i++) cout << g[i] << ' '; puts("");
	for(int i = 1; i <= n; i++) ans = min(ans, max(f[i], g[i]));
	cout << (int)ans << '\n';
	return 0;
}