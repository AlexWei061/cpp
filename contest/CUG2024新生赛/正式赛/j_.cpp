#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int k = 0;
double x_0 = 0, y_0 = 0;
struct Tsto{
	double x, y, r;
	double ll, rr;
	bool operator < (const Tsto &rhs) const{
		return ll < rhs.ll ? true : rr < rhs.rr;
	}
}s[MAXN];

int main(){
	cin >> x_0 >> y_0 >> k;
	for(int i = 1; i <= k; i++)
		cin >> s[i].x >> s[i].y >> s[i].r;
	for(int i = 1; i <= k; i++){
		if(s[i].r <= abs(s[i].y - y_0)) continue;
		s[i].ll = s[i].x - sqrt(s[i].r * s[i].r - (s[i].y - y_0) * (s[i].y - y_0));
		s[i].rr = s[i].x + sqrt(s[i].r * s[i].r - (s[i].y - y_0) * (s[i].y - y_0));
	}
	sort(s + 1, s + k + 1);
	double ans = 0;
	double lll = x_0, rrr = x_0;
	for(int i = 1; i <= k; i++){
		if(s[i].r <= abs(s[i].y - y_0)) continue;
		if(s[i].rr <= x_0) continue;
		s[i].ll = x_0 > s[i].ll ? x_0 : s[i].ll;
		if(lll <= s[i].ll and s[i].ll <= rrr)
			if(s[i].rr > rrr) ans += s[i].rr - rrr, rrr = s[i].rr;
		if(s[i].ll > rrr) ans += s[i].rr - s[i].ll, lll = s[i].ll, rrr = s[i].ll;
	}
	printf("%lf\n", ans);
	return 0;
}
