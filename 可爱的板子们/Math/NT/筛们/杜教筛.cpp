#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001000
#define ll long long

int T = 0; int n = 0;
bool vi[MAXN] = { 0 };
int pri[MAXN] = { 0 }; int m = 0;
ll   ph[MAXN] = { 0 };
int  mu[MAXN] = { 0 };
unordered_map<int, ll> P, M;

void Sieve(int n){
	mu[1] = ph[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!vi[i]) pri[++m] = i, ph[i] = i - 1, mu[i] = -1;
		for(int j = 1; j <= m; j++){
			if(i * pri[j] > n) break;
			vi[i * pri[j]] = 1;
			if(i % pri[j] == 0){
				ph[i * pri[j]] = ph[i] * pri[j];
				mu[i * pri[j]] = 0; break;
			}
			mu[i * pri[j]] = -mu[i];
			ph[i * pri[j]] = ph[i] * (pri[j] - 1);
		}
	}
	for(int i = 2; i <= n; i++)
		mu[i] += mu[i - 1], ph[i] += ph[i - 1];
}

ll Phi(ll n){
	if(n <= 1e7) return ph[n];
	if(P.count(n)) return P[n];
	ll x = 1ll * n * (n + 1) / 2;
	for(ll l = 2, r; l <= n; l = r + 1){
		int v = n / l; r = n / v;
		x -= 1ll * (r - l + 1) * Phi(v);
	}
	return P[n] = x;
}

ll Mu(ll n){
	if(n <= 1e7) return mu[n];
	if(M.count(n)) return M[n];
	ll x = 1;
	for(ll l = 2, r; l <= n; l = r + 1){
		int v = n / l; r = n / v;
		x -= 1ll * (r - l + 1) * Mu(v);
	}
	return M[n] = x;
} 

int main(){
	cin >> T;
	Sieve(1e7);
	while(T--){
		cin >> n;
		M.clear(); P.clear();
		cout << Phi(n) << ' ' << Mu(n) << '\n';
	}
	return 0;
}
