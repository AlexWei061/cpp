#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXM 2 * MAXN

int n = 0;
int m = 0;
int cnt = 0;
int a[MAXN] = { 0 };

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int   deg[MAXN] = { 0 };

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	deg[y]++;
}

void topsort(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(deg[i] == 0){
			q.push(i);
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			a[++cnt] = x;
			for(int e = first[x]; e; e = nxt[e]){
				int y = to[e];
				if(--deg[y] == 0){
					q.push(y);
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	
	topsort();
	
	for(int i = 1; i <= cnt; i++){
		printf("%d ", a[i]);
	}
	puts("");
	
	return 0;
}
