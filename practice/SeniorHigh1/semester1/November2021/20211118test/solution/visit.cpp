#include <bits/stdc++.h>
using namespace std;

#define N 100005

inline void rd(int &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int n,m,a[N];
int hd[N],_hd;

struct edge{
    int v,nxt;
}e[N<<1];

inline void addedge(int u,int v){
    e[++_hd]=(edge){v,hd[u]};
    hd[u]=_hd;
}

int fa[N],dep[N],sz[N],son[N];

inline void dfs1(int u,int Fa){
    fa[u]=Fa;
    dep[u]=dep[Fa]+1;
    sz[u]=1;
    for(int i=hd[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==Fa)
            continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])
            son[u]=v;
    }
}

int id[N],_id,pos[N],top[N];

inline void dfs2(int u){
    id[u]=++_id;
    pos[_id]=u;
    top[u]=u==son[fa[u]]?top[fa[u]]:u;
    if(son[u])
        dfs2(son[u]);
    for(int i=hd[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa[u]||v==son[u])
            continue;
        dfs2(v);
    }
}

std::set<int> s[N<<2];
inline void build(int p,int L,int R){
    for(int i=L;i<=R;i++)
        s[p].insert(a[pos[i]]);
    if(L==R)
        return;
    int mid=(L+R)>>1;
    build(p<<1,L,mid);
    build(p<<1|1,mid+1,R);
}

inline bool sch(int p,int L,int R,int l,int r,int x){
    if(L>r||R<l)
        return 0;
    if(l<=L&&R<=r)
        return s[p].count(x);
    int mid=(L+R)>>1;
    return sch(p<<1,L,mid,l,r,x)||sch(p<<1|1,mid+1,R,l,r,x);
}

inline bool lca_sch(int u,int v,int x){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])
            std::swap(u,v);
        if(sch(1,1,n,id[top[u]],id[u],x))
            return 1;
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])
        std::swap(u,v);
    return sch(1,1,n,id[v],id[u],x);
}

int main(){
	freopen("visit.in","r",stdin);
	freopen("visit.out","w",stdout);
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        rd(u),rd(v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,0);
    dfs2(1);
    build(1,1,n);
    while(m--){
        int u,v,x;
        rd(u),rd(v),rd(x);
        printf("%d",lca_sch(u,v,x));
    }
    #define w 0
    return ~~('0')?(0^w^0):(0*w*0);
}
