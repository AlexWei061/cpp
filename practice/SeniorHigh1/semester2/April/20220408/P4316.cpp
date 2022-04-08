#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 4 * MAXN

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
double f[MAXN] = { 0 };
int  deg[MAXN] = { 0 };
int  ing[MAXN] = { 0 };

queue<int> q;
void dp(){
	q.push(n);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int e = first[x]; e; e = nxt[e]){
			int y = to[e];
			f[y] += (double)(f[x] + value[e]) / deg[y];
			if(!(--ing[y])) q.push(y);
		}
	}
}

int main(){
	n = in; m = in;
	for(int i = 1; i <= m; i++){
		int x = in; int y = in; int w = in;
		add(y, x, w); ing[x]++; deg[x]++;
	} dp();
	printf("%.2lf\n", f[1]);
	return 0;
}