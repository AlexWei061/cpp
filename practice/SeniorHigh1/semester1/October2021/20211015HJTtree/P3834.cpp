#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n, q, m, cnt = 0;
int a[MAXN], b[MAXN], T[MAXN];
int sum[MAXN << 5], L[MAXN << 5], R[MAXN << 5];

inline int build(int l, int r){
    int rt = ++ cnt;
    sum[rt] = 0;
    if (l < r){
        int mid = (l + r) >> 1;
        L[rt] = build(l, mid);
        R[rt] = build(mid + 1, r);
    }
    return rt;
}

inline int update(int pre, int l, int r, int x){
    int rt = ++ cnt;
    L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre] + 1;
    if (l < r){
        int mid = (l + r) >> 1;
        if (x <= mid) L[rt] = update(L[pre], l, mid, x);
        else R[rt] = update(R[pre], mid + 1, r, x);
    }
    return rt;
}

inline int query(int u, int v, int l, int r, int k){
    if (l >= r) return l;
    int mid = (l + r) >> 1;
    int x = sum[L[v]] - sum[L[u]];
    if (x >= k) return query(L[u], L[v], l, mid, k);
    else return query(R[u], R[v], mid + 1, r, k - x);
}

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    
    sort(b+1, b+1+n);
    m = unique(b + 1, b + n + 1) - b - 1;
    
    T[0] = build(1, m);
    
    for (int i = 1; i <= n; i ++){
        int t = lower_bound(b + 1, b + m + 1, a[i]) - b;
        T[i] = update(T[i - 1], 1, m, t);
    }
    
    while(q--){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int t = query(T[x - 1], T[y], 1, m, z);
        printf("%d\n", b[t]);
    }
    return 0;
}
