#include<bits/stdc++.h>
#define ls x<<1,l,mid
#define rs x<<1|1,mid+1,r
#define N 500005
#define M 2000005
using namespace std;

int n;
int head[N],ver[M],nxt[M],tot;

void add(int a,int b)
{
    tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;return ;
}

int low[N],in[N],top,st[N],dfn[N],be[N],num,tim;

void trjan(int x)
{
    low[x]=dfn[x]=++tim;
    st[++top]=x;
    in[x]=1;
    for(int i=head[x];i;i=nxt[i])
    {
        if(!dfn[ver[i]])
        {
            trjan(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }
        else if(in[ver[i]])low[x]=min(low[x],dfn[ver[i]]);
    }
    if(low[x]==dfn[x])
    {
        int y;num++;
        do
        {
            y=st[top--];
            in[y]=0;
            be[y]=num;
        }while(y!=x);
    }
    return ;
}

struct nd
{
    int x,id;
    friend bool operator < (const nd &aa,const nd &bb)
    {
        return aa.x<bb.x;
    }
}a[N];
int tt,mx;
int fan[N];

void build(int x,int l,int r)
{
    mx=max(mx,x);
    if(l==r)
    {
        add(x+tt,fan[a[l].id]);
        return ;
    }
    int mid=(l+r)>>1;
    add(x+tt,x*2+tt);
    add(x+tt,x*2+1+tt);
    build(ls);build(rs);
}

void add(int x,int l,int r,int ll,int rr,int ps)
{
    if(l>=ll&&r<=rr)
    {
        add(ps,x+tt);
        return ;
    }
    int mid=(l+r)>>1;
    if(ll<=mid)add(ls,ll,rr,ps);
    if(rr>mid)add(rs,ll,rr,ps);
}

bool pan(int x)
{
    memset(dfn,0,sizeof(dfn));
    memset(head,0,sizeof(head));
    tot=tim=num=0;
    build(1,1,tt);
    int l=1,r=1;
    for(int i=1;i<=tt;i++)
    {
        while(l<i&&a[i].x-a[l].x>=x)l++;
        while(r<=tt&&a[r+1].x-a[i].x<x)r++;
        if(l!=i)add(1,1,tt,l,i-1,a[i].id);
        if(r!=i)add(1,1,tt,i+1,r,a[i].id);
    }
    for(int i=1;i<=tt+mx;i++)if(!dfn[i])trjan(i);
    for(int i=1;i<=tt;i++)if(be[i]==be[fan[i]])return 0;
    return 1;
}

int main()
{
	freopen("flags.in","r",stdin);
	freopen("flags.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t1,t2;cin>>t1>>t2;
        a[++tt].x=t1;a[tt].id=tt;
        a[++tt].x=t2;a[tt].id=tt;
        fan[tt-1]=tt;fan[tt]=tt-1;
    }
    sort(a+1,a+tt+1);
    int l=0,r=1000000000;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(pan(mid))l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}

