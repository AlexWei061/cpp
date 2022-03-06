#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1000100
#define MAXM MAXN * 2

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <=c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int tot = 0;
struct Tval{
	int dat, idx;
}val[MAXM];
int vis[MAXN] = { 0 };
inline bool comp(Tval a, Tval b) { return a.dat < b.dat; }

int main(){
	n = in;
	for(int i = 1; i <= n; i++){
		int a = in; int b = in;
		val[++tot].dat = a; val[tot].idx = i;
		val[++tot].dat = b; val[tot].idx = i;
	}
	sort(val + 1, val + tot + 1, comp);
	int prev = 0;
	for(int i = 1; i <= tot; i++){
//		printf("d = %d id =%d\n", val[i].dat, val[i].idx);
		Tval node = val[i];
		if(!vis[node.idx] and node.dat == prev + 1){ vis[node.idx] = 1; prev++; }
	}
	cout << prev << '\n';
	return 0;
}