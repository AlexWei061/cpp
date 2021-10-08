#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFI 1 << 30
#define MAXN 100100
#define MAXM 2 * MAXN

inline int read(){
    int x = 0;
    char c = getchar();
    while(c > '9' or c<'0'){
		c = getchar();
	}
    while(c >= '0' and c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
    return x;
}

int n = 0; int m = 0;
int s = 0; int t = 0;

int tot = 1;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int value[MAXM] = { 0 };

void add(int x, int y, int weight){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	value[tot] = weight;
}

int vis[MAXN] = { 0 };
struct Tpre{
	int v;
	int edge;
}pre[MAXN];

bool bfs(){
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	queue<int> q;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int e = first[u]; e; e= nxt[e]){
			int v = to[e];
			if(!vis[v] and value[e]){
				pre[v].v = u;
				pre[v].edge = e;
				if(v == t){
					return 1;
				}
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return 0; 
}

ll EK(){
	ll ans = 0;
	while(bfs()){
		int mmin = INFI;
		for(int i = t; i != s; i = pre[i].v){
			mmin = min(mmin, value[pre[i].edge]);
		}
		for(int i = t; i != s; i = pre[i].v){
			value[pre[i].edge] -= mmin;
			value[pre[i].edge ^ 1] += mmin;
		}
		ans += mmin;
	}
	return ans;
}

int main(){
	n = read(); m = read();
	s = read(); t = read();
	for(int i = 1; i <= m; i++){
		int u = 0; int v = 0; int w = 0;
		u = read(); v = read(); w = read();
		add(u, v, w); add(v, u, 0);
	}
	
	printf("%lld\n", EK());
	
	return 0;
}
