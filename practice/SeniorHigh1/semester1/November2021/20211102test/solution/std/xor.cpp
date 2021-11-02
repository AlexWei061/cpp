//
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
double p;

inline double fail(ll n) {
	double ret = 0.0;
	int cnt = 0;
	for (ll _n = n - 1; _n > 0LL; ++cnt, _n >>= 1) ;
	for (int i = cnt; i > 0; --i) {
		ll zero = (n >> i) * (1LL << i - 1) + min(n - (n >> i << i), 1LL << i - 1);
		double p = (double)(n - zero) / n;
		ret += (1.0 - p) * (1LL << i - 1) * p;
	}
	return ret * 2.0;
}

inline double success(ll n) {
	if (n == 1) return 0.0;
	double ret = 0.0;
	ll v = 1LL, delta, num;
	for (--n; v <= n; v <<= 1) ;
	delta = v - 1LL, v >>= 1;
	ret += (double)delta * (n - v + 1);
	ret += (double)v * v;
	num = v, delta >>= 1;
	while (v != 1) {
		v >>= 1, delta >>= 1;
		if (n & v) {
			ret += (double)num * v;
			ret += (double)(num >> 1) * delta;
			num >>= 1;
		} else ret += (double)(num >> 1) * v;
	}
	return ret / (double)(n + 1);
}

int main(int argc, char* argv[]) {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	scanf("%lld%lf", &n, &p);
	
	double ans1 = fail(n), ans2 = success(n);
	double ans = (1.0 - p) * ans1 + p * ans2;
	int b = 0;
	while (ans >= 10.0) ans /= 10.0, ++b;
	while (ans > 0.0 && ans < 1.0) ans *= 10.0, --b;
	printf("%.8f %d\n", ans, b);
	return 0;
}

