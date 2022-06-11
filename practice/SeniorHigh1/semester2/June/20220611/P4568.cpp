#include<bits/stdc++.h>
using namespace std;
#define in read() 
#define MAXN 2002000
#define MAXM 10050000
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int s = 0; int t = 0;
int n = 0; int m = 0; int k = 0;

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
priority_queue<pair<int , int>> q;

void djikstra(int node){
	memset(dis, 0x3f, sizeof(dis));
	dis[node] = 0; q.push(make_pair(0, node));
	while(!q.empty()){
		int x = q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			if(dis[y] > dis[x] + value[e]){
				dis[y] = dis[x] + value[e];
				q.push(make_pair(-dis[y], y));
			}
		}
	}
}

int main(){
	n = in; m = in; k = in;
	s = in; t = in; int ans = INFI;
	for(int i = 1; i <= m; i++){
		int x = in, y = in, w = in;
		for(int j = 0; j <= k; j++) add(j * n + x, j * n + y, w), add(j * n + y, j * n + x, w);
		for(int j = 0; j <  k; j++) add(j * n + x, (j + 1) * n + y, 0), add(j * n + y, (j + 1) * n + x, 0);
	}
	djikstra(s);
	for(int i = 0; i <= k; i++) ans = min(ans, dis[i * n + t]);
	cout << ans << '\n';
	return 0;
}