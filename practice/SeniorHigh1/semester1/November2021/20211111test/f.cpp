#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 202
#define MAXM 202
#define endl '\n'

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
int value[MAXM] = { 0 };
int  cost[MAXM] = { 0 };

inline void add(int x, int y, int c){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y; cost[tot] = c;
}

struct Tnode{
	int idx;
	int depth;
};
queue<Tnode> q;
int bfs(){
	q.push((Tnode){1, 0});
	while(!q.empty()){
		Tnode t = q.front(); q.pop();
		for(int e = first[t.idx]; e; e = nxt[e])
			if(t.depth >= cost[e]){
				int y = to[e];
				q.push((Tnode){y, t.depth + 1});
				if(y == n) return t.depth + 1;
			}
	}
}

int main(){
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in; int y = in;
		int c = in; add(x, y, c);
	}
	cout << bfs() << endl;
	return 0;
}
