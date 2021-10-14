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

const int P = 998244353;
int power(int x, int y){
	int i = x; x = 1;
	while (y != 0){
		if (y % 2 == 1) x = 1ll * x * i % P;
		y = y / 2;
		i = 1ll * i * i % P;
	}
	return x;
}

const int N = 100010, inv2 = power(2, P - 2);

void upd(unsigned &x, unsigned y){ x = x + y >= P ? x + y - P : x + y; }
void mulupd(int &x, int y){ x = 1ll * x * y % P;}
int n, a[N], num[N], cnt, mul[N];
unsigned dp[2][N][3];
unsigned ch(unsigned x){
	if (x < P) return x;
		else if (x < P + P) return x - P;
		else return x - P - P;
}
int main(){
	freopen("record.in", "r", stdin);
	freopen("record.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	bool flag = true;
	cnt = 0;
	for (int i = 1; i <= n; i += a[i]){
		num[++cnt] = a[i];
		for (int j = i + 1; j < i + a[i]; j++) 
			if (a[j] != a[i]) flag = false;
	}
	if (!flag){
		printf("%d\n", 0);
		return 0;
	}
	int t0 = 0, t1 = 1;
	if (num[1] != 1) 
		dp[t0][0][0] = dp[t0][0][1] = 1;
		else dp[t0][0][2] = 1;
	for (int i = 2; i <= cnt; i++){
		for (int j = 0; j < i; j++){
			dp[t1][j][0] = dp[t1][j][1] = dp[t1][j][2] = 0;
			if (num[i] != 1){
				upd(dp[t1][j][0], ch(dp[t0][j][1] + dp[t0][j][0] + dp[t0][j][2]));
				upd(dp[t1][j][1], ch(dp[t0][j][1] + dp[t0][j][0] + dp[t0][j][2]));
			}
			else upd(dp[t1][j][2], ch(dp[t0][j][1] + dp[t0][j][0] + dp[t0][j][2]));
			if (j > 0){
				upd(dp[t1][j][0], ch(dp[t0][j - 1][0] + dp[t0][j - 1][2]));
				upd(dp[t1][j][1], ch(dp[t0][j - 1][1] + dp[t0][j - 1][2]));
			}
		}
		swap(t0, t1);
//		if (i % 100 == 0) cerr << i << endl;
	}
	unsigned ans = 0;
	mul[0] = 1; for (int i = 1; i <= cnt; i++) mul[i] = 1ll * mul[i - 1] * i % P;
	for (int i = 0; i <= cnt; i++){
		unsigned now = 1ll * ch(dp[t0][i][0] + dp[t0][i][1] + dp[t0][i][2]) * mul[cnt - i] % P;
		if (i % 2 == 0) upd(ans, now);
			else upd(ans, P - now);
	}
	printf("%d\n", ans);
    return 0;
}

