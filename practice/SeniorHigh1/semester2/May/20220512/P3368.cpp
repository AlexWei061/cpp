#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-')f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int a[MAXN] = { 0 };
int c[MAXN] = { 0 };
int n = 0; int m = 0;
int t[MAXN * 4] = { 0 };

inline int lowbit(int x) { return x & (-x); }
void add(int x, int y){
	for(; x <= n; x += lowbit(x)) t[x] += y;
}
int query(int x){
	int ans = 0;
	for(; x; x -= lowbit(x)) ans += t[x];
	return ans;
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++){
		c[i] = a[i] - a[i - 1]; add(i, c[i]);
	}
	while(m--){
		int op = in;
		if(op == 1){
			int l = in; int r = in; int x = in;
			add(l, x); add(r + 1, -x);
		}
		else{
			int x = in;
			cout << query(x) << '\n';
		} 
	}
	return 0;
}