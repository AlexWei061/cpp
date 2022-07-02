#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM MAXN << 2

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int t = 0;
int n = 0; int m = 0;
int a[MAXN] = { 0 };
int tot = 0; int cnt = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int   deg[MAXN] = { 0 };
inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y; deg[y]++;
}

void init(){
	tot = cnt = 0;
	memset(a, 0, sizeof(a));
	memset(to, 0, sizeof(to));
	memset(nxt, 0, sizeof(nxt));
	memset(deg, 0, sizeof(deg));
	memset(first, 0, sizeof(first));
}

priority_queue<int> q;
void topsort(){
	for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x = q.top(); q.pop();
		a[++cnt] = x;
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(!(--deg[y])) q.push(y);
		}
	}
}

int main(){
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	t = in;
	while(t--){
		init();
		n = in; m = in;
		for(int i = 1; i <= m; i++){
			int x = in, y = in;
			add(y, x);
		} topsort();
		if(cnt < n) cout << "Impossible!\n";
		else { for(int i = n; i >= 1; i--) cout << a[i] << ' '; puts(""); }
	}
	return 0;
}
