# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int N = 100100, K = 510;
ll num[N], n, l[K], ans[N], len[K], one, cost[K], k;
int main(){
	freopen("buy.in", "r", stdin);
	freopen("buy.out", "w", stdout);
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(num[i]);
	for (int i = 1; i <= k; i++){
		read(len[i]); read(cost[i]);
		l[i] = 1;
	}
	read(one);
	ans[0] = 0;
	for (int i = 1; i <= n; i++){
		ans[i] = ans[i - 1] + one;
		for (int j = 1; j <= k; j++){
			while (num[i] - num[l[j]] >= len[j]) l[j]++;
			chmin(ans[i], ans[l[j] - 1] + cost[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld\n", ans[i] - ans[i - 1]);
    return 0;
}

