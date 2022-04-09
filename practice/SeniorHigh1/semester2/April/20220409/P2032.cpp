#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 2002000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c= getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int k = 0;

struct TMonotoneQueue{
	
	int idx[MAXN];
	int q[MAXN]; int head; int tail;
	
	void mmax(){
		head = 1; tail = 0;
		for(int i = 1; i <= n; i++){
			while(head <= tail and a[i] >= q[tail]) tail--;
			q[++tail] = a[i]; idx[tail] = i;
			while(idx[head] <= i - k) head++;
			if(i >= k) cout << q[head] << '\n'; 
		}
	}
	
}solve;

int main(){
	n = in; k = in;
	for(int i = 1; i <= n; i++) a[i] = in; solve.mmax();
	return 0;
}