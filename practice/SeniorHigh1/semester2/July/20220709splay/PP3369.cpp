#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define INFI 2147483647
#define ls(p) ch[p][0]
#define rs(p) ch[p][1]

inline int read(){
    int x = 0; int f = 1; char c = getchar();
    while(c < '0' or c > '9') {
        if(c == '-')f = -1; c = getchar();
    }
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return f * x;
}

int n = 0, tot = 0, root = 0, ans = 0;;
int val[MAXN] = { 0 };
int ch[MAXN][2] = { 0 }, fa[MAXN] = { 0 };
int size[MAXN] = { 0 }, cnt[MAXN] = { 0 };

inline bool get(int x) { return rs(fa[x]) == x; }                                  // 是不是右儿子
inline void up(int x) { size[x] = size[ls(x)] + size[rs(x)] + cnt[x]; }            // 上传信息

void rot(int x){
    int y = fa[x], z = fa[y], k = get(x);
    ch[z][get(y)] = x; fa[x] = z;
    ch[y][k] = ch[x][k ^ 1]; fa[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y; fa[y] = x; up(y); up(x);
}

void spl(int x, int to){
    if(x == 0) return;
    while(fa[x] != to){
        int y = fa[x];
        if(fa[y] != to) rot(get(x) ^ get(y) ? x : y);
        rot(x);
    } if(!to) root = x;
}

void ins(int x){
    int p = root; int f = 0;
    while(p and val[p] != x) f = p, p = ch[p][x > val[p]];
    if(p) cnt[p]++;
    else{
        p = ++tot;
        if(f) ch[f][x > val[f]] = p;
        fa[p] = f; size[p] = cnt[p] = 1; val[p] = x;
    }
    spl(p, 0);
}

void pre(int p, int x){
    if(!p) return;
    if(val[p] < x) ans = p, pre(rs(p), x);
    else pre(ls(p), x);
}

void suf(int p, int x){
    if(!p) return;
    if(val[p] > x) ans = p, suf(ls(p), x);
    else suf(rs(p), x);
}

void del(int x){
    pre(root, x); int lst = ans;
    suf(root, x); int nxt = ans;
    spl(lst, 0); spl(nxt, lst);
    int d = ls(nxt);
    if(cnt[d] > 1) cnt[d]--, spl(d, 0);
    else ls(nxt) = 0;
}

int rank_x(int p, int x){
    if(x < val[p]) return rank_x(ls(p), x);
    else if(x > val[p]) return rank_x(rs(p), x) + size[ls(p)] + cnt[p];
    else return size[ls(p)] + 1;
}

int rank_k(int p, int k){
    if(size[ls(p)] >= k) return rank_k(ls(p), k);
    else if(size[ls(p)] + cnt[p] < k) return rank_k(rs(p), k - size[ls(p)] - cnt[p]);
    else return val[p];
}

int main(){
    n = in;
    ins(INFI), ins(-INFI);
    for(int i = 1; i <= n; i++){
        int op = in, x = in;
        if(op == 1) ins(x);
        if(op == 2) del(x);
        if(op == 3) cout << rank_x(root, x) - 1 << '\n';
        if(op == 4) cout << rank_k(root, x + 1) << '\n';
        if(op == 5) pre(root, x), cout << val[ans] << '\n';
        if(op == 6) suf(root, x), cout << val[ans] << '\n';
    }
    return 0;
}