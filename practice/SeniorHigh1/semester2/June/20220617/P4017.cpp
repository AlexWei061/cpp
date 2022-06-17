#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 500500 << 1
#define MOD 80112002

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int  rdep[MAXN] = { 0 };
int  cdep[MAXN] = { 0 };

inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

queue<int> q;
int val[MAXN] = { 0 };
void bfs(){
	for(int i = 1; i <= n; i++) if(!rdep[i]) q.push(i), val[i] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			val[y] = (val[y] % MOD + val[x] % MOD) % MOD;
			if(!(--rdep[y])) q.push(y);
		}
	}
}

int main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= m; i++){
		int x = in, y = in;
		add(y, x), rdep[x]++, cdep[y]++;
	}
//	for(int i = 1; i <= n; i++) cout << rdep[i] << ' '; puts("");
//	for(int i = 1; i <= n; i++) cout << cdep[i] << ' '; puts("");
	bfs();
	for(int i = 1; i <= n; i++) if(!cdep[i]) ans = (ans % MOD + val[i] % MOD) % MOD;
	cout << ans << '\n';
	return 0;
}