#include<bits/stdc++.h>
using namespace std;
#define MAXN 50500
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int t = 0; int k = 0;
int a = 0; int b = 0;
int c = 0; int d = 0;

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

int cal(int n, int m){
	int r = min(n, m);
	int ans = 0;
	for(int i = 1; i <= r; i++){
		int temp = mu[i] * (n / (i * k)) * (m / (i * k));
		ans += temp;
	}
	return ans;
}

int main(){
	t = in;
	mobius(50000);
	while(t--){
		a = in; b = in;
		c = in; d = in;
		k = in;
		int ans = cal(b, d) - cal(a - 1, d) - cal(b, c - 1) + cal(a - 1, c - 1);
		cout <<  ans << '\n';
	}
	return 0;
}
```

&emsp; 下面我们考虑怎么样优化处理这个式子的时间。首先看看这个式子的样子，他长得是不是就很像整除分块qwq，那就直接整除分块计算这个式子，复杂度就被降到了 $O(\sqrt{min(n, m)})$，·这样一来就能过了（不知道为什在 luogu 上过不了，但是在 bzoj上就一次过了）。bzoj 传送门：[bzoj 2301](https://vjudge.net/problem/%E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8-2301)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAXN 50500
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int t = 0; int k = 0;
int a = 0; int b = 0;
int c = 0; int d = 0;

int v[MAXN] = { 0 };
int mu[MAXN] = { 0 };
int sum[MAXN] = { 0 };
void mobius(int n){
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
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + mu[i];
}

int cal(int n, int m){
	int x = min(n, m);
	int ans = 0;
	for(int l = 1, r; l <= x; l = r + 1){
		r = min(n / (n / l), m / (m / l));
		ans += (n / (l * k)) * (m / (l * k)) * (sum[r] - sum[l - 1]);
	}
	return ans;
}

int main(){
	t = in;
	mobius(50000);
	while(t--){
		a = in; b = in;
		c = in; d = in;
		k = in;
		int ans = cal(b, d) - cal(a - 1, d) - cal(b, c - 1) + cal(a - 1, c - 1);
		cout <<  ans << '\n';
	}
	return 0;
}