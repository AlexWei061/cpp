#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001000

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c- '0'; c = getchar();
	}
	return f * x;
}

int n = 0; int k = 0;
int a[MAXN] = { 0 };

struct TMonotoneQueue{
	
	int idx[MAXN];
	int q[MAXN]; int head; int tail;
	
	void mmin(){
		head = 1; tail = 0;
		for(int i = 1; i <= n; i++){
			while(head <= tail and q[tail] >= a[i]) tail--;
			q[++tail] = a[i]; idx[tail] = i;
  			while(idx[head] <= i - k) head++;
  			if(i >= k) cout << q[head] << ' ';
		}
		puts("");  
	}
	
	void mmax(){
		head = 1; tail = 0;
		for(int i = 1; i <= n; i++){
			while(head <= tail and q[tail] <= a[i]) tail--;
			q[++tail] = a[i]; idx[tail] = i;
			while(idx[head] <= i - k) head++;
			if(i >= k) cout << q[head] << ' ';
		}
		puts("");
	}
	
}solve;

int main(){
	n = in; k = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	solve.mmin(); solve.mmax();
	return 0;
}