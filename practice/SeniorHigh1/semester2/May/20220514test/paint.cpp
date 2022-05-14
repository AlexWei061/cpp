#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define INFI 1 << 30

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0; int k = 0;
struct Tnode{
	int sx, sy;
	int tx, ty;
	int ts, tt;
}tag[MAXN];
int fa[MAXN] = { 0 };

int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	n = in; m = in; k = in; int cnt = 0;
	if(n == 1 and m == 1) { cout << 1 << '\n'; return 0; }
	for(int i = 1; i <= k; i++) fa[i] = i;
	int c[n + 10][m + 10];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			c[i][j] = in;
	for(int i = 1; i <= k; i++) tag[i].sx = tag[i].sy = INFI, tag[i].tx = tag[i].ty = -INFI;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			tag[c[i][j]].sx = min(tag[c[i][j]].sx, i);
			tag[c[i][j]].sy = min(tag[c[i][j]].sy, j);
			tag[c[i][j]].tx = max(tag[c[i][j]].tx, i);
			tag[c[i][j]].ty = max(tag[c[i][j]].ty, j);
		}
	for(int x = 1; x <= k; x++){
		if(tag[x].sx == INFI) continue;
		for(int i = tag[x].sx; i <= tag[x].tx; i++)
			for(int j = tag[x].sy; j <= tag[x].ty; j++)
				if(c[i][j] != x and fa[c[i][j]] == c[i][j]) cnt++, fa[c[i][j]] = 0;
	}
	cout << k - cnt << '\n';
	return 0;
}