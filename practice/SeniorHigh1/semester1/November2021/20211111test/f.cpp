#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 202
#define INFI 0x3f3f3f3f

inline int read(){
	int x = 0; int f = 1;
	char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int n = 0; int m = 0;
bitset<MAXN> dis[32][MAXN];

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int ans = INFI;
int d[MAXN] = { 0 };
int bfs(int node){
	memset(d, 0x3f, sizeof(d));
	d[node] = 0;
	queue<int> q; q.push(node);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(d[y] > d[x]){
				d[y] = d[x] + 1; q.push(y);
			}
		}
	}
	return d[n];
}

int l = 0;
struct Tnode{
	int s, t, d;
}a[MAXN];
inline bool comp(Tnode x, Tnode y){
	return x.d < y.d;
}

void work(int up){                                        // 快速幂
	for(int k = 0; k <= 30; k++)
		for(int i = 1; i <= n; i++) dis[k][i].reset();
	for(int i = 1; i <= l; i++) dis[0][a[i].s][a[i].t] = 1;
	for(int k = 1; k <= up; k++){
		for(int i = 1; i <= n; i++){
			if(!dis[k-1][i].count()) continue;
			for(int j = 1; j <= n; j++){
				if(dis[k-1][j][i]) dis[k][j] |= dis[k-1][i];
			}
		}
	}
}

bitset<MAXN> g;
bitset<MAXN> temp;

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		a[i].s = in; a[i].t = in; a[i].d = in;
	} sort(a + 1, a + m + 1, comp);
	if(n == 1) { puts("0"); return 0; }
	g[1] = 1;
	while(l < m){
		int deltaD = a[l + 1].d - a[l].d;
		if(deltaD){
			int up = 0;
			while((1 << up) <= deltaD) up++;
			up--; work(up);
			for(int k = 0; k <= up; k++){                 // 更新 g
				if(!((deltaD >> k) & 1)) continue;
				temp.reset();
				for(int i = 1; i <= n; i++)
					if(g[i]) temp |= dis[k][i];
				g = temp;
			}
		}
		l++; add(a[l].s, a[l].t);
		for(int i = 1; i <= n; i++)
			if(g[i]) ans = min(ans, a[l].d + bfs(i));     // bfs 更新答案
	}
	printf("%d\n", ans);
	return 0;
}
