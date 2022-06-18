#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 200200
const int INFI = 2e9;

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int n = 0;
int l = 0; int r = 0;
int a[MAXN] = { 0 };
int f[MAXN] = { 0 };

int q[MAXN] = { 0 };
int head = 0, tail = 0;
void ins(int i){
	while(head <= tail and f[q[tail]] <= f[i]) tail--;
	q[++tail] = i;
}
int query(int i){
	while(q[head] + r < i) head++;
	return q[head];
}

int main(){
	n = in; l = in; r = in; int ans = -INFI;
	for(int i = 0; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) f[i] = -INFI; f[0] = 0;
	for(int i = l; i <= n; i++){
		ins(i - l);
		int j = query(i);
		f[i] = f[j] + a[i];
		if(i + r > n) ans = max(ans, f[i]);
	}
	cout << ans << '\n';
	return 0;
}