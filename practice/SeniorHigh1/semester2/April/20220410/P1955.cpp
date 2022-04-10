#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 2002000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int t = 0;
struct Tnode{
	int e;
	int x; int y;
	bool operator < (const Tnode &rhs) const {
		return e > rhs.e;
	}
}st[MAXN];
int cnt = 0;
int a[MAXN * 2] = { 0 };

int fa[MAXN] = { 0 };
void init(int n) { for(int i = 1; i <= n; i++) fa[i] = i; }
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	t = in;
	while(t--){
		int n = in; bool flag = 0;
		for(int i = 1; i <= n; i++){
			st[i].x = in, st[i].y = in, st[i].e = in;
			a[++cnt] = st[i].x; a[++cnt] = st[i].y;
		} sort(a + 1, a + cnt + 1); init(cnt);
		sort(st + 1, st + n + 1); int k = unique(a + 1, a + cnt + 1) - a;
		for(int i = 1; i <= n; i++){
			st[i].x = lower_bound(a + 1, a + k + 1, st[i].x) - a;
			st[i].y = lower_bound(a + 1, a + k + 1, st[i].y) - a;
		} 
		for(int i = 1; i <= n; i++){
			int fax = find(st[i].x); int fay = find(st[i].y);
			if(st[i].e == 1) fa[fax] = fay;
			else if(fax == fay) { flag = 1; goto end; }
		}
		end : if(flag) puts("NO"); else puts("YES"); 
	}
    return 0;
}