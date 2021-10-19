#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in read()
#define MAXN 200200

ll read(){
	ll x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

ll n = 0; ll k = 0;
ll a[MAXN] = { 0 };
ll c[10 * MAXN] = { 0 };

ll cnt = 0;
ll idx[MAXN] = { 0 };

inline ll lowbit(ll x){
	return x & -x;
}

inline void add(ll index, ll val){
	for(; index <= n; index += lowbit(index)){
		c[index] += val;
	}
}

inline ll query(ll x){
	ll ans = 0;
	for(; x; x -= lowbit(x)){
		ans += c[x];
	}
	return ans;
}

ll inverPair(ll n, ll a[]){
	//memset(c, 0, sizeof(c));
	for(ll i = 1; i <= 4 * k; i++) c[i] = 0;
	ll ans = 0;
	for(ll i = n; i >= 1; i--){
		ans += query(a[i] - 1);
		add(a[i], 1ll);
		/*
		printf("  "); 
		for(int j = 1; j <= 4 * n; j++){
			printf("%d ", c[j]);
		}
		puts("");
		*/
	}
	return ans;
}

ll dfs(ll x){
	ll ans = 0;
	if(x > cnt - 1ll){
		/*
		printf("x = %d\n", x);
		for(int i = 1; i <= n; i++){
			printf("%d ", a[i]);
		}
		puts("");
		printf("%d\n\n", inverPair(n, a));
		*/
		return inverPair(n, a);
	}
	for(ll i = 1; i <= k; i++){
		a[idx[x + 1ll]] = i;
		//printf("x = %d i = %d\n", x, i);
		ans = max(ans, dfs(x + 1ll));
		a[idx[x + 1ll]] = 0;
	}
	return ans;
}

int main(){
	n = in; k = in;
	for(int i = 1; i <= n; i++){
		a[i] = in;
		if(a[i] == 0){
			//cnt++; idx = i;
			idx[++cnt] = i;
		}
	}
	
	if(cnt == 0){
		printf("%lld\n", inverPair(n, a));
		return 0;	
	}
	else if(cnt == n){
		ll ans = 0;
		for(ll i = 1ll; i <= k - 1; i++){
			ans += (n / k) * (n - i * (n / k));
		}
		printf("%lld\n", ans);
		return 0;
	}
	else if(cnt == 1){
		ll ans = 0;
		for(ll i = 1ll; i <= k; i++){
			a[idx[1]] = i;
			ans = max(ans, inverPair(n, a));
			a[idx[1]] = 0;
		}
		printf("%lld\n", ans);
		return 0;
	}
	
	if(n <= 8 and k <= 8){
		printf("%lld\n", dfs(0));
	}
	else{
		printf("%lld\n", dfs(0));
	}
	
	return 0;
}