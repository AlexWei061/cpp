#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define INFI int(1e9)

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

struct Tnode{
    int dat;
    int ls, rs;
}t[MAXN << 5];
int tot = 0;
int root[MAXN] = { 0 };

inline void up(int p) { t[p].dat = t[t[p].ls].dat + t[t[p].rs].dat; }
int update(int now, int l, int r, int x, int val){
    int p = ++tot; t[p] = t[now];
    if(l == r) { t[p].dat += val; return p; }
    int mid = (l + r) >> 1;
    if(x <= mid) t[p].ls = update(t[p].ls, l, mid, x, val);
    else t[p].rs = update(t[p].rs, mid + 1, r,  x, val);
    up(p); return p;
}

int query(int p, int q, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr) { return t[p].dat - t[q].dat; }
    int mid = (l + r) >> 1; int ans = 0;
    if(ql <= mid) ans += query(t[p].ls, t[q].ls, l, mid, ql, qr);
    if(qr > mid) ans += query(t[p].rs, t[q].rs, mid + 1, r, ql, qr);
    return ans;
}

int main(){
    n = in;
    for(int i = 1; i <= n; i++) a[i] = in;
    for(int i = 1; i <= n; i++) root[i] = update(root[i - 1], 1, INFI, a[i], a[i]);
    m = in;
    while(m--){
        int l = in; int r = in; int ans = 1;
        while(1){
            int res = query(root[r], root[l - 1], 1, INFI, 1, ans);
            if(res >= ans) ans = res + 1;
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}