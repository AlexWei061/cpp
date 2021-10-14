#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN 1001000

int n = 0; int m = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int c[MAXN] = { 0 };

inline void discrete(){
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - b - 1;
}

inline int query(int x){
	return lower_bound(b + 1, b + m + 1, x) - b;
}

inline int lowbit(int x){
	return x & -x;
}

inline void add(int index, int val){
	for(; index <= n; index += lowbit(index)){
		c[index] += val;
	}
}

inline ll ask(int x){
	ll ans = 0;
	for(; x; x -= lowbit(x)){
		ans += c[x];
	}
	return ans;
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		
		discrete();
		
		ll ans = 0;
		for(int i = n; i >= 1; i--){
			int k = query(a[i]);
			ans += ask(k - 1);
			add(k, 1);
		}
		//printf("%d\n", ans);
		
		ll sum = ans;
		for(int i = 1; i <= n; i++){
				ans += n - a[i] - a[i] - 1;
				sum = min(sum, ans);
		}
		printf("%d\n", sum);	
	}
	return 0;
}
