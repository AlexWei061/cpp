#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXM 2 * MAXN
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define endl '\n'

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int a[MAXN] = { 0 };
int n = 0; int m = 0;

int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };

inline void add(int x, int y){
    nxt[++tot] = first[x];
    first[x] = tot; to[tot] = y;
}

int  dep[MAXN] = { 0 };
int   fa[MAXN] = { 0 };
int size[MAXN] = { 0 };
int  son[MAXN] = { 0 };
void dfs1(int x, int father,  int depth){
    dep[x] = depth; fa[x] = father; size[x] = 1;
    for(int e = first[x]; e; e = nxt[e]){
        int y = to[e];
        if(y != father){
            dfs1(y, x, depth+1);
            size[x] += size[y];
            if(size[y] > size[son[x]]) son[x] = y;
        }
    }
}

int cnt = 0;
int top[MAXN] = { 0 };
int idx[MAXN] = { 0 };
int pos[MAXN] = { 0 };
void dfs2(int x, int t){
    top[x] = t; idx[x] = ++cnt; pos[cnt] = x;
    if(!son[x]) return;
    dfs2(son[x], t);
    for(int e = first[x]; e; e = nxt[e]){
        int y = to[e];
        if(y != fa[x] and y != son[x]) dfs2(y, y);
    }
}

set<int> s[MAXN * 4];
void build(int p, int l, int r){
    for(int i = l; i <= r; i++)
        s[p].insert(a[pos[i]]);
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
}

bool search(int p, int l, int r, int ql, int qr, int x){
    if(l > qr or r < ql) return false;
    if(ql <= l and r <= qr)
        return s[p].count(x);
    int mid = (l + r) >> 1;
    bool ll = search(ls(p), l, mid, ql, qr, x);
    bool rr = search(rs(p), mid + 1, r, ql, qr, x);
    return ll or rr;
}

bool lca(int x, int y, int v){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        if(search(1, 1, n, idx[top[x]], idx[x], v))
            return true;
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    return search(1, 1, n, idx[x], idx[y], v);
}

int ans[MAXN] = { 0 };
int main(){
    n = in; m = in;
    // printf("n = %d m = %d\n", n, m);
    for(int i = 1; i <= n; i++)  a[i] = in;
    for(int i = 1; i < n; i++){
        int x = in; int y = in;
        add(x, y); add(y, x);
    }
    dfs1(1, 0, 1); dfs2(1, 1); build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int x = in; int y = in; int v = in;
        ans[i] = lca(x, y, v); 
    }
    for(int i = 1; i <= m; i++) cout << ans[i];
    puts("");
    return 0;
}