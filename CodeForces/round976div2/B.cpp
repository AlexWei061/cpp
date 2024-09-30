#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define in read()
#define MAXN 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int t = 0;
int x = 0;

int cal(int x){
	int l = 1, r = x + 1;
	while(l < r){                                    // 二分答案 
		int mid = l + r >> 1;
//		int val = mid * mid - mid;
//		if(val <= x) l = mid + 1;
//		else r = mid;
		double val = (1 + sqrt(1 + 4 * x)) / 2;
		if(mid > val) r = mid;
		else l = mid + 1;
	} l--;
//	printf("l = %d\n", l);
	if(l * l - l == x) return l * l - 1; 
	else return l * l + (x - (l * l - l));
}

// 打表 
int a[MAXN] = { 0 };
void p(int x){
	for(int i = 1; i <= x; i++) a[i] = 1;
	for(int i = 1; i <= x; i++)
		for(int j = 1; i * j <= x; j++)
			if(a[i * j] == 1) a[i * j] = 0;
			else a[i * j] = 1;
	for(int i = 1; i <= x; i++) cout << a[i] << ' '; puts("");
}

signed main(){
	t = in;
	while(t--){
		x = in;
//		p(x);
		cout << cal(x) << '\n';
	}
	return 0;
}
