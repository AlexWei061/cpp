#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int m = 0; int p = 0;
struct Tnode{
	int x;
	int l, r;
}a[MAXN];
int  fa[MAXN] = { 0 };
int siz[MAXN] = { 0 };

int find(int x){
	if(x != fa[x]){
		int f = find(fa[x]);
		siz[x] += siz[fa[x]];
		fa[x] = f;
	}
	return fa[x];
}

int main(){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	n = in; m = in; p = in; bool flag = 0;
	for(int i = 1; i <= m; i++) a[i].l = in, a[i].r = in, a[i].x = in;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int fax = find(a[i].l - 1); int fay = find(a[i].r);
		if(fax != fay)
			fa[fax] = fay, siz[fax] = a[i].x + siz[a[i].l - 1] + siz[a[i].r];
		else
			if((siz[a[i].l - 1] - siz[a[i].r]) % p != a[i].x) { cout << i - 1 << '\n'; flag = 1; break; }
	}
	if(!flag) cout << m << '\n';
	return 0;
}