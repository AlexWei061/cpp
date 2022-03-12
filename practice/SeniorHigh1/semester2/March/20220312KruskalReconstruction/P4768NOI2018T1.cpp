#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN (int)(4e5 + 10)

inline int read(){
    int x = 0; char ch = getchar();
    while(ch < '0' or ch > '9') ch = getchar();
    while(ch >= '0' and ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}

int T = 0;
int n = 0; int m = 0;
int lastans = 0;
struct node{
    int u, v, l, a, nxt;
    bool operator < (const node &b) const{
        return a > b.a;                      //小根堆
    }
}e[MAXN << 1], tmp[MAXN << 1], edge[MAXN << 1];

int tot, first[MAXN], dis[MAXN];
struct heap{
    int x, dis;
    bool operator < (const heap &b) const{
        return dis > b.dis;
    }
};
int f[MAXN], cnt;

inline void Add(int x, int y, int z){
    edge[++tot].v = y; edge[tot].l = z;
		edge[tot].nxt = first[x]; first[x] = tot;
}

inline void dijkstra(){    //求出从1到各点的最短路
    priority_queue <heap> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0; q.push((heap){1, 0});
    while(!q.empty()){
        heap now = q.top(); q.pop();
        int x = now.x;
        if(dis[x] < now.dis) continue;
        for(int e = first[x]; e; e = edge[e].nxt){
            int y = edge[e].v;
            if(dis[y] > dis[x] + edge[e].l){
                dis[y] = dis[x] + edge[e].l;
                q.push((heap){y, dis[y]});
            }
        }
    }
}

inline int find(int x){
		if(x == f[x]) return f[x];
		else return f[x] = find(f[x]);
}

inline void add(int x, int y){
    edge[++tot].v = y;
		edge[tot].nxt = first[x];
    first[x] = tot;
}

inline void kruskal(){
    sort(e + 1, e + 1 + m);
    for(int i = 1; i <= n; i++) f[i] = i;
    cnt = n; int num = 0;
    for(int i = 1; i <= m; i++){
        int fu = find(e[i].u), fv = find(e[i].v);
        if(fu != fv){
            num++;
            tmp[++cnt].a = e[i].a;
            f[fu] = f[fv] = f[cnt] = cnt;
            add(cnt, fu), add(cnt, fv);
        }
        if(num == n - 1) break;
    }
}

int fa[MAXN][20], dep[MAXN];

inline void dfs(int x, int p){
    dep[x] = dep[p] + 1, fa[x][0] = p;
    for(int i = 1; i <= 19; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = first[x]; i; i = edge[i].nxt){
        int y = edge[i].v;
        dfs(y, x);
        tmp[x].l = min(tmp[x].l, tmp[y].l);
    }
}

inline int query(int x, int y){ //从x出发往上跳，找到海拔大于y的最小的点
    for(int i = 19; i >= 0; i--)
        if(dep[x] - (1 << i) > 0 && tmp[fa[x][i]].a > y)
            x = fa[x][i];
    return tmp[x].l;
}

inline void solve(){
    kruskal();
    dfs(cnt, 0);
    int q = read(), k = read(), s = read();
    while(q--){
        int x = (k * lastans + read() - 1) % n + 1, y = (k * lastans + read()) % (s + 1);
        printf("%d\n", lastans = query(x, y));
    }
}

inline void init(){
    memset(first, 0, sizeof(first));
    memset(fa, 0, sizeof(fa));
    memset(f, 0, sizeof(f));
    memset(tmp, 0, sizeof(tmp));
    memset(edge, 0, sizeof(edge));
    lastans = tot = 0;
}

int main(){
    T = read();
    while(T--){
        init();
        n = read(), m = read();
        for(int i = 1; i <= m; i++){
            e[i].u = read(), e[i].v = read(), e[i].l = read(), e[i].a = read();
            Add(e[i].u, e[i].v, e[i].l), Add(e[i].v, e[i].u, e[i].l);
        }
        dijkstra();
        for(int i = 1; i <= n; i++) tmp[i].l = dis[i];
        for(int i = n + 1; i <= (n << 1); i++) tmp[i].l = INF;
        memset(first, 0, sizeof(first)), tot = 0;
        solve();
    }
    return 0;
}
