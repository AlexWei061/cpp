#include<bits/stdc++.h>
using namespace std;
#define MAXN 1 << 22
#define eps 1e-6
#define pi acos(-1.0)

int n = 0; int m = 0;
complex<double> a[MAXN], b[MAXN];

void FFT(complex<double> *a, int n, int inv){
	if(n == 1) return;
	int mid = n / 2;
	complex<double> Al[mid + 1], Ar[mid + 1];
	for(int i = 0; i <= n; i += 2){
		Al[i / 2] = a[i];
		Ar[i / 2] = a[i + 1];
	}
	FFT(Al, mid, inv);
	FFT(Ar, mid, inv);
	complex<double> w0(1, 0), wn(cos(2 * pi / n), inv * sin(2 * pi / n));
	for(int i = 0; i < mid; i++, w0 *= wn){
		a[i] = Al[i] + w0 * Ar[i];
		a[i + n / 2] = Al[i] - w0 * Ar[i];
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++){
		double x = 0;
		scanf("%lf", &x);
		a[i].real(x);
	}
	for(int i = 0; i <= m; i++){
		double x = 0;
		scanf("%lf", &x);
		b[i].real(x);
	}
	int len = 1 << max((int)ceil(log2(n + m)), 1);
	FFT(a, len, 1);
	FFT(b, len, 1);
	for(int i = 0; i <= len; i++) a[i] *= b[i];
	FFT(a, len, -1);
	for(int i = 0; i <= n + m; i++) printf("%0.f ", a[i].real() / len + eps);
	return 0;
}
