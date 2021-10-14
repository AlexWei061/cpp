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

const int N = 700;
int num[N + 10], dp[N * N + 10];
int main(){
	freopen("intersect.in", "r", stdin);
	freopen("intersect.out", "w", stdout);
	for (int i = 1; i <= N; i++) num[i] = i * (i - 1) / 2;
	memset(dp, inf, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i <= N * (N - 1) / 2; i++)
		for (int j = 1; j <= N; j++){
			if (i + num[j] > N * (N - 1) / 2) continue;
			chmin(dp[i + num[j]], dp[i] + j);
		}
	int opt;
	read(opt);
	while (opt--){	
		int n, m;
		read(n); read(m);
		if (m > n * (n - 1) / 2){
			printf("0\n");
			continue;
		}
		if (dp[n * (n - 1) / 2 - m] <= n)
			printf("%d\n", 1);
			else printf("%d\n", 0);
	}
    return 0;
}

