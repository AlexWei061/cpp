#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

char ss[MAXN];
int n = 0; int m = 0;
int ans[MAXM] = { 0 };

int fa[MAXN] = { 0 };

void init(){
	for(int i = 0; i <= n; i++) fa[i] = i;
}

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	fa[find(x)] = find(y);
}

int main(){
	n = in; m = in;
	init();
	scanf("%s", ss+1);
	for(int i = 1; i < n; i++){
		int x = in; int y = in;
		if(ss[x] == ss[y]) merge(x, y);
	}
	for(int i = 1; i <= m; i++){
		int s = in; int t = in;
		char temp = getchar();
		if(find(s) == find(t) and ss[s] != temp) ans[i] = 0;
		else ans[i] = 1;
	}
	for(int i = 1; i <= m; i++) cout << ans[i];
	puts("");
	return 0;
}