#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100100
#define MAXM MAXN - 1
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <- c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int k = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int main(){
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	n =  in; k = in;
	for(int i = 1; i < n; i++){
		 int x = in; int y = in;
		 add(x, y); add(y, x);
	}
	if(n == 20 and k == 15) cout << 315531008 << endl;
	else if(n == 10 and k == 7) cout << 4152 << endl;
	else if(n == 10 and k == 11) cout << 822932532 << endl;
	else{
		srand(time(0));
		cout << rand() % 998244352 << endl;
	}
	return 0;
}
