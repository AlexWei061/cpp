#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int T = 0;
int n = 0;
int a[MAXN] = { 0 };
namespace ans{
	int mmax = 0;
	int ind = 0;
	int solve(){
		mmax = ind = 0;
		for(int i = 1; i <= n; i++)
			if((a[i] > mmax) or (a[i] == mmax and i % 2 == 1)) mmax = a[i], ind = i;
//		printf("mmax = %d ind = %d\n", mmax, ind);
	//	if(n % 2 == 0) return (n / 2) + mmax;
	//	else if(ind % 2 == 1) return ((n / 2) + 1) + mmax;
	//	else return (n / 2) + mmax;
		if(n % 2 == 1 and ind % 2 == 1) return ((n / 2) + 1) + mmax;
		else return (n / 2) + mmax;
	}
} 

int main(){
	T = in;
//	freopen("a.out", "w", stdout);
	while(T--){
		n = in;
		for(int i = 1; i <= n; i++) a[i] = in;
		cout << ans::solve() << '\n';
	}
	return 0;
}
