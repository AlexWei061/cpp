#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 10010

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
struct Tmice{
	int t;
	int x, y;
}mi[MAXN];
int f[MAXN] = { 0 };

int main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= m; i++) mi[i].t = in, mi[i].x = in, mi[i].y = in, f[i] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j < i; j++){
			int xi = mi[i].x, yi = mi[i].y, ti = mi[i].t;
			int xj = mi[j].x, yj = mi[j].y, tj = mi[j].t;
			if(abs(xi - xj) + abs(yi - yj) <= abs(ti - tj))
				f[i] = max(f[i], f[j] + 1);
		}
	for(int i = 1; i <= m; i++) ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
}