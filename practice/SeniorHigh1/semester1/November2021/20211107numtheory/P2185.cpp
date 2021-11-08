#include<bits/stdc++.h>
using namespace std;
#define MAXN 40400
#define endl '\n'

int n = 0;

int v[MAXN] = { 0 };
int mu[MAXN] = { 0 };
void mobius(int n){
	memset(v, 0, sizeof(v));
	for(int i = 1; i <= n; i++) mu[i] = 1;
	for(int i = 2; i <= n; i++){
		if(v[i]) continue;
		mu[i] = -1;
		for(int j = 2 * i; j <= n; j += i){
			v[j] = 1;
			if((j / i) % i == 0) mu[j] = 0;
			else mu[j] *= -1;
		}
	}
}

int main(){
	scanf("%d", &n); n -= 1;
	if(n == 0){
		cout << 0 << endl; return 0;
	}
	mobius(n);
	int ans = 0;
	for(int d = 1; d <= n; d++){
		int temp = mu[d] * (n / d) * (n / d);
		ans += temp;
	}
	ans += 2;
	cout << ans << endl;
	return 0;
}