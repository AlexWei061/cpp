#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1000000000000005;
const ll maxn=5e5+5;
const int mod=998244353;

ll n,m;
int deep[maxn];//树的深度
int f[maxn][30];//fa[i][j] 节点i的2^j次方的祖先

struct node{
    int e,next;
}edge[maxn];

ll cnt=0;
int head[maxn];
int dis[maxn];
char str[maxn];

void addedge(int u,int v)
{
    edge[cnt]=node{v,head[u]};
    head[u]=cnt++;
}

void dfs(int u,int fa,int z)//预处理深度 与祖先的关系
{
    deep[u]=deep[fa]+1;
    dis[u]=dis[fa]+z;
    f[u][0]=fa;
    for(int i=1;(1<<i)<=deep[u];i++)//不加限制也行
        f[u][i]=f[f[u][i-1]][i-1];//2^i = 2^(i-1)+2^(i-1)
    for(int i=head[u];~i;i=edge[i].next){
        int e=edge[i].e;
        int w;
        if(e!=fa) dfs(e,u,(str[e]=='G'?1:-1));
    }
}

int LCA(int u,int v)
{
    if(deep[u]<deep[v]) swap(u,v);//保持u比v深
    for(int i=25;i>=0;i--)   if(deep[f[u][i]]>=deep[v]) u=f[u][i];//比他深往上跳
    if(u==v) return u;
    for(int i=25;i>=0;i--){
        if(f[u][i]!=f[v][i]){//因为从同一深度开始向上跳 一样有可能是更远的祖先
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];//随便返回一个上一级即可
}

int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%lld%lld",&n,&m);
    scanf("%s",str+1);
    for(int i=1;i<=n-1;i++)
    {
        ll x,y;scanf("%lld%lld",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    int tempx=(str[1]=='G'?1:-1);
    dfs(1,1,tempx);
    for(int i=1;i<=m;i++)
    {
        ll x,y;
        char op[5];
        scanf("%lld%lld%s",&x,&y,op);
        int amit=LCA(x,y);
        int dis1=deep[x]+deep[y]-2*deep[amit]+1;
        int dis2=dis[x]+dis[y]-2*dis[amit]+(str[amit]=='G'?1:-1);
        if(dis2>-dis1&&dis2<dis1) printf("1");
        else if(dis2==dis1&&op[0]=='G') printf("1");
        else if(dis2==dis1&&op[0]=='H') printf("0");
        else if(dis2==-dis1&&op[0]=='G') printf("0");
        else if(dis2==-dis1&&op[0]=='H') printf("1");
    }
    printf("\n");
    return 0;
}

