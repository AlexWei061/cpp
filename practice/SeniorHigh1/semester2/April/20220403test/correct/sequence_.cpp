#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define INFI 1e6
#define MAXN 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x ;
}

int n = 0;
int L = 0; int R = 0;
int a[MAXN] = { 0 };

bool check(double avr){
	static double s[MAXN]; static double q[MAXN];
	static int head; static int tail; static int pos[MAXN];
	head = 1; tail = 0;
	for(int i = 1; i <= n; i++) s[i] = 1.0 * a[i] - avr + s[i - 1];         // 减后的前缀和 
	for(int i = L; i <= n; i++){                                            // 单调队列 
		while(head <= tail and q[tail] >= s[i - L]) tail--;
		while(head <= tail and pos[head] + R < i) head++;
		q[++tail] = s[i - L]; pos[tail] = i - L;
		if(s[i] >= q[head]) return true;
	}
	return false;
}

signed main(){
	double mid = 0;
	n = in; L = in; R = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	double l = 0; double r = INFI;
	for(int t = 1; t <= 100; t++){                                         // 二分答案 (平均值) 
		mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.4lf\n", mid);
	return 0;
}
