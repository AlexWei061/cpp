#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXM 2 * MAXN

int t = 0; int n = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
int   deg[MAXN] = { 0 };
int value[MAXN] = { 0 };
int limit[MAXN] = { 0 };

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
	deg[x]++; deg[y]++;
}

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			int x, y; scanf("%d%d", &x, &y);
			add(x, y); add(y, x);
		}
		for(int i = 1; i <= n; i++){
			int b, p; scanf("%d%d", &b, &p);
			value[i] = b; limit[i] = p;
		}
		
	}
	return 0;
}
