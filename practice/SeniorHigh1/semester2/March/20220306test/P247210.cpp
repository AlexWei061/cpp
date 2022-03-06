#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXM 25 * MAXN
#define INFI 1 << 20

int maxflow = 0; int num = 0;
int n = 0; int m = 0; int dis = 0;
int s = 0; int t = 20002;
int mmap[MAXN][MAXN] = { 0 };
int lizard[MAXN][MAXN] = { 0 };

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

inline void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	value[tot] = weight;
}
inline int ask(int i, int j) { return i * (m + 2) + j + 1; }
inline int ask1(int i, int j) { return i * (m + 2) + j + 1; }
inline int ask2(int i, int j) { return ask1(i, j) + (m + 1) * (n + 1); }

queue<int> q;
int d[MAXN * MAXN] = { 0 };
int now[MAXN * MAXN] = { 0 };

bool bfs(){
	memset(d, 0, sizeof(d));
	while(q.size()) q.pop();
	q.push(s); d[s] = 1; now[s] = first[s];
	while(q.size()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(value[e] and !d[y]){
				q.push(y); now[y] = first[y];
				d[y] = d[x] + 1;
				if(y == t) return true;
			}
		}
	}
	return false;
}

int dinic(int x, int flow){
	if(x == t) return flow;
	int rest = flow; int e = 0;
	for(e = first[x]; e and rest; e = nxt[e]){
		int y = to[e];
		if(value[e] and d[y] == d[x] + 1){
			int k = dinic(y, min(rest, value[e]));
			if(!k) d[y] = 0;
			value[e] -= k; value[e ^ 1] += k;
			rest -= k;
		}
	}
	now[x] = e;
	return flow - rest;
}

void input(){
		scanf("%d%d%d\n", &n, &m, &dis);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c; scanf("%c", &c);
			mmap[i][j] = c - '0';
		}
		scanf("\n");
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c; scanf("%c", &c);
			if(c == '.') lizard[i][j] = 0;
			else { lizard[i][j] = 1; num++; }
		}
		if(i != n) scanf("\n");
	}
}

void build1(){
		for(int i = 0; i <= n + 1; i++)
			for(int j = 0; j <= m + 1; j++){
				if(lizard[i][j]){
					add(s, ask(i, j), 1);
					add(ask(i, j), s, 0);
				}
				if(i == 0 or j == 0 or i == n + 1 or j == m + 1){
					add(ask(i, j), t, INFI);
					add(t, ask(i, j), 0);
				}
			}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mmap[i][j]){
				for(int k = 1; k <= dis; k++){
					if(i + k <= n){
						add(ask(i, j), ask(i + k, j), mmap[i][j]);
						add(ask(i + k, j), ask(i, j), 0);
					}
					if(j + k <= m){
						add(ask(i, j), ask(i, j + k), mmap[i][j]);
						add(ask(i, j + k), ask(i, j), 0);
					}
					if(i >= k){
						add(ask(i, j), ask(i - k, j), mmap[i][j]);
						add(ask(i - k, j), ask(i, j), 0);
					}
					if(j >= k){
						add(ask(i, j), ask(i, j - k), mmap[i][j]);
						add(ask(i, j - k), ask(i, j), 0);
					}
				}
				for(int k = 1; k < dis; k++){
					for(int l = 1; l < dis; l++){
						if(i + k <= n and j + l <= m){
							add(ask(i, j), ask(i + k, j + l), mmap[i][j]);
							add(ask(i + k, j + l), ask(i, j), 0);
						}
						if(i + k <= n and j - l >= 0){
							add(ask(i, j), ask(i + k, j - l), mmap[i][j]);
							add(ask(i + k, j - l), ask(i, j), 0);
						}
						if(i - k >= 0 and j + l <= m){
							add(ask(i, j), ask(i - k, j + l), mmap[i][j]);
							add(ask(i - k, j + l), ask(i, j), 0);
						}
						if(i - k >= 0 and j - l >= 0){
							add(ask(i, j), ask(i - k, j - l), mmap[i][j]);
							add(ask(i - k, j - l), ask(i, j), 0);
						}
					}
				}
			}
		}
	}
}

void build(){
	for(int i = 0; i <= n + 1; i++)
			for(int j = 0; j <= m + 1; j++){
				add(ask2(i, j), ask1(i, j), mmap[i][j]);
				add(ask1(i, j), ask2(i, j), 0);
				if(lizard[i][j]){
					add(s, ask2(i, j), 1);
					add(ask1(i, j), s, 0);
				}
				if(i == 0 or j == 0 or i == n + 1 or j == m + 1){
					add(ask1(i, j), t, INFI);
					add(t, ask2(i, j), 0);
				}
			}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mmap[i][j]){
				for(int k = 1; k <= dis; k++){
					if(i + k <= n){
						add(ask1(i, j), ask2(i + k, j), mmap[i][j]);
						add(ask1(i + k, j), ask2(i, j), 0);
					}
					if(j + k <= m){
						add(ask1(i, j), ask2(i, j + k), mmap[i][j]);
						add(ask1(i, j + k), ask2(i, j), 0);
					}
					if(i >= k){
						add(ask1(i, j), ask2(i - k, j), mmap[i][j]);
						add(ask1(i - k, j), ask2(i, j), 0);
					}
					if(j >= k){
						add(ask1(i, j), ask2(i, j - k), mmap[i][j]);
						add(ask1(i, j - k), ask2(i, j), 0);
					}
				}
				for(int k = 1; k < dis; k++){
					for(int l = 1; l < dis; l++){
						if(i + k <= n and j + l <= m){
							add(ask1(i, j), ask2(i + k, j + l), mmap[i][j]);
							add(ask1(i + k, j + l), ask2(i, j), 0);
						}
						if(i + k <= n and j - l >= 0){
							add(ask1(i, j), ask2(i + k, j - l), mmap[i][j]);
							add(ask1(i + k, j - l), ask2(i, j), 0);
						}
						if(i - k >= 0 and j + l <= m){
							add(ask1(i, j), ask2(i - k, j + l), mmap[i][j]);
							add(ask1(i - k, j + l), ask2(i, j), 0);
						}
						if(i - k >= 0 and j - l >= 0){
							add(ask1(i, j), ask2(i - k, j - l), mmap[i][j]);
							add(ask1(i - k, j - l), ask2(i, j), 0);
						}
					}
				}
			}
		}
	}
}

void solve(){
	int flow = 0;
	while(bfs())
		while(flow = dinic(s, INFI)) maxflow += flow;
//	cout << maxflow << '\n';
	cout << num - maxflow << '\n';
}

int main(){
	input();
	build();
	solve();
	return 0;
}