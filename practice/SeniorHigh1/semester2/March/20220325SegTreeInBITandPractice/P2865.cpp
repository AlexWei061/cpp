#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 200200
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

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

int n = 0; int m = 0;
int dis[2][MAXN] = { 0 };

struct Tnode{
	int pos; int dis;
	bool operator < (const Tnode &rhs) const {
		return dis > rhs.dis;
	}
}temp;
priority_queue<Tnode> q;

void dijkstra(){
	temp.dis = 0; temp.pos = 1; q.push(temp);
	while(!q.empty()){
		Tnode temp = q.top(); q.pop();
		int x = temp.pos; int d = temp.dis;
		if(d > dis[1][x]) continue;
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e]; int w = value[e];
			if(dis[0][y] > d + w){
				dis[1][y] = dis[0][y];
				temp.dis = dis[0][y] = d + w;
				temp.pos = y; q.push(temp);
			}
			if(dis[1][y] > d + w and dis[0][y] < d + w){
				temp.dis = dis[1][y] = d + w;
				temp.pos = y; q.push(temp);
			}
		}
	}
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in; int y = in; int w = in;
		add(x, y, w); add(y, x, w);
	}
	for(int i = 1; i <= n; i++) dis[0][i] = dis[1][i] = INFI;
	dis[0][1] = 0; dijkstra();
	cout << dis[1][n] << '\n';
	return 0;
}