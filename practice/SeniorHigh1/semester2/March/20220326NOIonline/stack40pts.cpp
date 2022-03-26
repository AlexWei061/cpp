#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 5050
#define MAXM 500500

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int q = 0;
struct Tnode{
	int a; int b;
	bool operator < (const Tnode &x) const { return (a != x.a) and (b < x.b); }       // 能入栈的条件 
	bool operator >= (const Tnode &x) const { return !((*this) < x); }                // 能入栈的条件取反 
	bool operator == (const Tnode &x) const { return a == x.a; }
}arr[MAXM];

int ans[MAXN][MAXN] = { 0 };
int top = 0;
int stk[MAXN] = { 0 };
void solve1(){
	for(int i = 1; i <= n; top = 0, i++){
		ans[i][i] = 1; stk[++top] = i;
		for(int j = i + 1; j <= n; j++){
			while(top and arr[j] >= arr[stk[top]]) top--;
			ans[i][j] = ans[i][j - 1] + (top == 0); stk[++top] = j;
		}
	}
	while(q--) { int l = in; int r = in; cout << ans[l][r] << '\n'; }
}

void solvea(){
	return;
}

int suf[MAXM] = { 0 };
void solveb(){
	suf[n] = 1;
	for(int i = n - 1; i; i--){
		if(arr[i] == arr[i + 1]) suf[i] = suf[i + 1] + 1;
		else suf[i] = 1;
	}
	while(q--) { int l = in; int r = in; cout << suf[l] << '\n'; }
}

int main(){
	n = in;  q = in;
	bool flaga = 1; bool flagb = 1;
	for(int i = 1; i <= n; i++) if((arr[i].a = in) != i) flaga = 0;
	for(int i = 1; i <= n; i++) if((arr[i].b = in) != (n - i + 1)) flagb=0;
	if(flaga) solvea();
	else if(flagb) solveb();
	else {
		if(n <= 5000) solve1();
		else{
			
		}
	}
	return 0;
}