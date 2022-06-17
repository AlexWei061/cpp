#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 101

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int g[MAXN][MAXN] = { 0 };
int f[MAXN][MAXN] = { 0 };
struct Tnode{
	int val;
	int i, j;
	bool operator < (const Tnode &rhs) const {
		return val > rhs.val;
	}
};
priority_queue<Tnode> q;

int main(){
	n = in; m = in; int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			f[i][j] = 1;
			Tnode temp;
			temp.val = g[i][j] = in, temp.i = i, temp.j = j;
			q.push(temp);
		}
	while(!q.empty()){
		Tnode t = q.top();
		int i = t.i, j = t.j, val = t.val;
		q.pop();
		if(i + 1 <= n and g[i + 1][j] < val) f[i][j] = max(f[i][j], f[i + 1][j] + 1);
		if(i - 1 >= 1 and g[i - 1][j] < val) f[i][j] = max(f[i][j], f[i - 1][j] + 1);
		if(j + 1 <= m and g[i][j + 1] < val) f[i][j] = max(f[i][j], f[i][j + 1] + 1);
		if(j - 1 >= 0 and g[i][j - 1] < val) f[i][j] = max(f[i][j], f[i][j - 1] + 1);
		ans = max(ans, f[i][j]);
	}
	cout << ans << '\n';
	return 0;
}