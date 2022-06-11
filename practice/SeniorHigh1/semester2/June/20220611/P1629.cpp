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

int n = 0; int m = 0;
struct Gragh{
	
	int tot = 0;
	int first[MAXN], nxt[MAXM], to[MAXM], value[MAXM];
	
	inline void add(int x, int y, int weight){
		nxt[++tot] = first[x];
		first[x] = tot; to[tot] = y;
		value[tot] = weight;
	}
	
	int dis[MAXN], vis[MAXN];
	priority_queue<pair<int, int>> q;
	
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
	
}T1, T2;

int main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= m; i++){
		int x = in, y = in, w = in;
		T1.add(x, y, w), T2.add(y, x, w);
	}
	T1.djikstra(1); T2.djikstra(1);
//	for(int i = 1; i <= n; i++) cout << T1.dis[i] << ' '; puts("");
//	for(int i = 1; i <= n; i++) cout << T2.dis[i] << ' '; puts("");
	for(int i = 2; i <= n; i++)
		ans += (T1.dis[i] + T2.dis[i]);
	cout << ans << '\n';
	return 0;
}