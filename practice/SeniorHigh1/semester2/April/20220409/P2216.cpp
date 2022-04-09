#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 1010
#define INFI 0x3f3f3f3f

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int arr[MAXN][MAXN] = { 0 };
int a = 0; int b = 0; int n = 0;
int mmin[MAXN][MAXN] = { 0 };
int mmax[MAXN][MAXN] = { 0 };

struct TMonotoneQueue{

	int arr[MAXN]; int idx[MAXN];
	int q[MAXN]; int head; int tail;
	int mn[MAXN]; int mx[MAXN]; int N;
	void clear() { for(int i = 1; i <= N; i++) { mn[i] = mx[i] = 0; } }
	void mmin(){
		head = 1; tail = 0;
		for(int i = 1; i <= N; i++){
			while(head <= tail and arr[i] <= q[tail]) tail--;
			q[++tail] = arr[i]; idx[tail] = i;
			while(idx[head] <= i - n) head++;
			if(i >= n) mn[i] = q[head];	
		}
	}
	void mmax(){
		head = 1; tail = 0;
		for(int i = 1; i <= N; i++){
			while(head <= tail and arr[i] >= q[tail]) tail--;
			q[++tail] = arr[i]; idx[tail] = i;
			while(idx[head] <= i - n) head++;
			if(i >= n) mx[i] = q[head];
		}
	}
	
}solve;

signed main(){
	a = in; b = in; n = in; int ans = INFI;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			arr[i][j] = in;
	solve.N = b;
	for(int i = 1; i <= a; i++){
		solve.clear();
		for(int j = 1; j <= b; j++) solve.arr[j] = arr[i][j]; solve.mmax(); solve.mmin();
		for(int j = 1; j < b; j++) { mmax[i][j] = solve.mx[j + n - 1]; mmin[i][j] = solve.mn[j + n - 1]; }
	}
	solve.N = a;
	for(int j = 1; j < b; j++){
		solve.clear();
		for(int i = 1; i <= a; i++) solve.arr[i] = mmax[i][j]; solve.mmax();
		for(int i = 1; i <= a; i++) solve.arr[i] = mmin[i][j]; solve.mmin();
		for(int i = 1; i < a; i++) { mmax[i][j] = solve.mx[i + n - 1]; mmin[i][j] = solve.mn[i + n - 1]; }
	}
	for(int i = 1; i <= a - n + 1; i++)
		for(int j = 1; j <= b - n + 1; j++)
			ans = min(ans, mmax[i][j] - mmin[i][j]);
	cout << ans << '\n';
//	puts("");
//	for(int i = 1; i < a; i++){
//		for(int j = 1; j < b; j++){
//			cout << mmax[i][j] <<' ';
//		}
//		puts("");
//	}
//	puts("");
//	for(int i = 1; i < a; i++){
//		for(int j = 1; j < b; j++){
//			cout << mmin[i][j] <<' ';
//		}
//		puts("");
//	}
	
	return 0;
}