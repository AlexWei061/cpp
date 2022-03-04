#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define ls(p) ch[p][0]
#define rs(p) ch[p][1]
int n = 0; int m = 0; int a[MAXN] = { 0 }; int ch[MAXN][2] = { 0 }; int fa[MAXN] = { 0 }; int rv[MAXN] = { 0 }; int w[MAXN] = { 0 };
inline void up(int x) { w[x] = a[x] ^ w[ls(x)] ^ w[rs(x)]; }
inline bool isr(int x) { return ls(fa[x]) != x and rs(fa[x]) != x; }
inline bool get(int x) { return rs(fa[x]) == x; }
inline void rev(int x) { if(!x) return; swap(ls(x), rs(x)); rv[x] ^= 1; }
inline void down(int x) { if(rv[x]) rev(ls(x)), rev(rs(x)); rv[x] = 0; }
inline void rot(int x) { int y = fa[x]; int z = fa[y]; int k = get(x); if(!isr(y)) ch[z][get(y)] = x; fa[x] = z; ch[y][k] = ch[x][k ^ 1]; fa[ch[x][k ^ 1]] = y; ch[x][k ^ 1] = y; fa[y] = x; up(y); up(x); }
inline void path(int x) { if(!isr(x)) path(fa[x]); down(x); }
inline void spl(int x) { path(x); while(!isr(x)){ int y = fa[x]; if(!isr(y)) rot(get(x) ^ get(y) ? x : y); rot(x); } }
inline void acs(int x){ for(int y = 0; x; y = x, x = fa[x]) spl(x), rs(x) = y, up(x); }
inline void mrt(int x) { acs(x); spl(x); rev(x); }
inline int find(int x) { acs(x); spl(x); down(x); while(ls(x)) x = ls(x), down(x); spl(x); return x; }
inline void link(int x, int y) { mrt(x); if(find(y) == x) return; fa[x] = y; }
inline void cut(int x, int y){ mrt(x); acs(y); spl(y); if(ls(y) != x) return; ls(y) = fa[x] = 0; }
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), w[i] = a[i];
	for(int i = 1; i <= m; i++){
		int o, x, y; scanf("%d%d%d", &o, &x, &y);
		if(o == 0) { mrt(x); acs(y); spl(y); cout << w[y] << '\n'; }
		if(o == 1) link(x, y);
		if(o == 2) cut(x, y);
		if(o == 3) { acs(x); spl(x); a[x] = y, up(x); }
	}
	return 0;
}