#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 40400
#define MAXM MAXN * 8

inline int read(){
	int x  = 0; char c = getchar();
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
inline void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}

int px[10] = { 0, -1,  1, -2,  2, -1, 1, -2, 2 };
int py[10] = { 0, -2, -2, -1, -1,  2, 2,  1, 1 };
int n = 0; int p = 0;
char str[202];
int mmap[202][202] = { 0 };

inline int get(int x, int y) { return (x - 1) * n + y; }
void build(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!mmap[i][j] and (i + j) % 2)
				for(int k = 1; k <= 8; k++){
					int x = 0; int y = 0;
					x = i + px[k]; y = j + py[k];
					if(x < 1 or y < 1 or x > n or y > n or mmap[x][y]) continue;
					add(get(i, j), get(x, y));
				}
}

int match[MAXN] = { 0 };
int vis[MAXN] = { 0 };
bool dfs(int x){
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(!vis[y]){
			vis[y] = 1;
			if(!match[y] or dfs(match[y])){
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main(){
	n = in;
	for(int i = 1; i <= n; i++){
		scanf("%s", str + 1);
		for(int j = 1; j <= n; j++){
			mmap[i][j] = (str[j] == '1' ? 1 : 0);
			if(mmap[i][j]) p++;
		}
	}
	build();
	int v = n * n - p; int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!mmap[i][j] and (i + j) % 2){
				memset(vis, 0, sizeof(vis));
				if(dfs(get(i, j))) ans++;
			}
	cout << v - ans;
	return 0;
}