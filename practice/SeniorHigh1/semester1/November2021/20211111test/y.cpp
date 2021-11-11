#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int n = 0; int q = 0;

int b[5005][5005] = { 0 };
int f(int x, int y){
	for(int i = 1; i <= y; i++) b[1][i] = a[i];
	for(int i = 2; i <= x; i++) b[i][1] = b[i-1][1] + a[1];
	for(int i = 2; i <= x; i++){
		for(int j = 2; j <= y; j++){
			b[i][j] = min(b[i-1][j-1], b[i-1][j]) + a[j];
		}
	}
	return b[x][y];
}

int main(){
	n = in; q = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= q; i++){
		int x = in; int y = in;
		cout << f(x, y) << endl;
	}
	return 0;
}
