#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 5050
#define MAXM 100100
#define INFI 1 << 30

inline int read(){
	int x = 0; int f = 1; char c = getchar();
	while(c < '0' or c > '9'){
		if(c == '-') f = -1; c = getchar();
	}
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

int n = 0; int m = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

inline void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	value[tot] = weight;
}

int dis[MAXN] = { 0 };
int vis[MAXN] = { 0 };
int inq[MAXN] = { 0 };
queue<int> q;
bool SPFA(int s){
	for(int i = 1; i <= n; i++) dis[i] = INFI;
	dis[s] = 0, vis[s] = 1, inq[s] = 1; q.push(s);
	while(!q.empty()){
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(dis[y] > dis[x] + value[e]){
				dis[y] = dis[x] + value[e];
				if(!vis[y]){
					q.push(y); ++inq[y], vis[y] = 1;
					if(inq[y] == n + 1) return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in, y = in, k = in; add(y, x, k);
	}
	for(int i = 1; i <= n; i++) add(0, i, 0);
	if(SPFA(0)) cout << "NO" << '\n';
	else for(int i = 1; i <= n; i++) cout << dis[i] << ' ';
	return 0;
}