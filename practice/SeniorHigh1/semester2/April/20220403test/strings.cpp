#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM MAXN * 4

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
string value[MAXM];

inline void add(int x, int y, string weight){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	value[tot] = weight;
}

int dep[MAXN] = { 0 };
int f[MAXN][30] = { 0 };

void prework(int x, int fa){
	for(int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fa){
			dep[y] = dep[x] + 1; f[y][0] = x;
			prework(y);
		}
	}
}

int queryLca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20; i; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}

int t[MAXN][50] = { 0 };

void build(){

}

int main(){
	n = in;
	for(int i = 1; i < n; i++){
		int x = in; int y = in; string s; cin >> s;
		add(x, y, s); add(y, x, s);
	}
	return 0;
}
