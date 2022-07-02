#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n = 0; int m = 0;
int mmap1[MAXN][MAXN] = { 0 };
int mmap2[MAXN][MAXN] = { 0 };

bool flag = 0;
bool chk(int a[]){
	bool temp = true;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++){
			int x = a[i], y = a[j];
			if(mmap1[i][j])
				if(!mmap2[x][y]) temp = false;
		}
	return temp;
}

int a[MAXN] = { 0 };
bool vis[MAXN] = { 0 };
void dfs(int x){
	if(x == n + 1){
		if(chk(a)) flag = 1;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1; a[x] = i;
		dfs(x + 1);
		vis[i] = 0; a[x] = 0;
	}
}

int main(){
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x = 0, y = 0;
		cin >> x >> y;
		mmap1[x][y] = mmap1[y][x] = 1;
	}
	for(int i = 1; i <= m; i++){
		int x = 0, y = 0;
		cin >> x >> y;
		mmap2[x][y] = mmap2[y][x] = 1;
	}
	dfs(1);
	flag ? cout << "Yes" << '\n' : cout << "No" << '\n';
	return 0;
}
