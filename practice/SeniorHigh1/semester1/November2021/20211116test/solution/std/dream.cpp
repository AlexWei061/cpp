#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
const int inf=0x3f3f3f3f;
struct node{int size,id,iid;};
struct edge{int last,en,next;} e[200010];
int n,x,y,son[100010],size[100010],dfn[100010],dep[100010];
int st[100010][18],tot,cnt,cs[100010],q,u,v,ccs[100010];
int f[100010][18],val[100010],g[100010][18],leave[100010],ans,w,sum;
void add(int x,int y)
{
	e[++tot].en=y;
	e[tot].next=e[x].last;
	e[x].last=tot;
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s; 
}
void dfs(int x,int fa)
{
    f[x][0]=fa;dep[x]=dep[fa]+1;size[x]=1;
	dfn[x]=++cnt;son[x]=0;
    for(int i=e[x].last;i;i=e[i].next) 
	    if (e[i].en!=fa)
		{
			dfs(e[i].en,x);
			if (size[son[x]]<size[e[i].en])
			{
				ccs[x]=cs[x];
				cs[x]=son[x];
				son[x]=e[i].en;
			}
			else if (size[cs[x]]<size[e[i].en]) 
			{
				ccs[x]=cs[x];
				cs[x]=e[i].en;
			}
			else if (size[ccs[x]]<size[e[i].en]) ccs[x]=e[i].en;
			size[x]+=size[e[i].en];
		}
	val[x]=size[son[x]]-size[cs[x]];
	if (!cs[x]) val[x]=0x3f3f3f3f; 
	st[x][0]=val[x];g[x][0]=son[x];
    leave[x]=++tot;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=17;i>=0;i--)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int calc(int z,int x)
{
	if (dfn[u]>=dfn[x]&&leave[u]<=leave[x]) z-=size[u];
	if (dfn[v]>=dfn[x]&&leave[v]<=leave[x]) z-=size[v];
	return z;
}
bool getpos(int x,int y)
{
	if (dfn[x]>=dfn[y]&&leave[x]<=leave[y]) return true;
	return false;
}
void sort3(node &a,node &b,node &c)
{
	if (a.size<b.size) swap(a,b);
	if (a.size<c.size) swap(a,c);
	if (b.size<c.size) swap(b,c);
}
void sort3(int &a,int &b,int &c)
{
	if (a<b) swap(a,b);
	if (a<c) swap(a,c);
	if (b<c) swap(b,c);
}
bool get(int x)
{
	int a,b,c;
	a=calc(size[son[x]],son[x]);
	b=calc(size[cs[x]],cs[x]);
	c=calc(size[ccs[x]],ccs[x]);
	sort3(a,b,c);
	if (a<=sum/2) return true;
	return false;
}
void getans(int x)
{
	for (int i=17;i>=0;i--)
		if (f[x][i]&&get(f[x][i])) x=f[x][i];
	int y=0;
	node a,b,c;
	a=(node){calc(size[son[x]],son[x]),getpos(u,son[x])?u:getpos(v,son[x])?v:0,son[x]};
	if (son[x]==u||son[x]==v) a.size=-inf;
	b=(node){calc(size[cs[x]],cs[x]),getpos(u,cs[x])?u:getpos(v,cs[x])?v:0,cs[x]};
	if (son[x]==u||son[x]==v) a.size=-inf;
	c=(node){calc(size[ccs[x]],ccs[x]),getpos(u,ccs[x])?u:getpos(v,ccs[x])?v:0,ccs[x]};
	if (son[x]==u||son[x]==v) a.size=-inf;
	sort3(a,b,c);
	if (sum-a.size<=sum/2&&a.size!=-inf) y=a.iid;
	if (x>y) swap(x,y);
	if (x) printf("%d %d\n",x,y);
	else printf("%d\n",y);
}
void solve(int x)
{
	bool bj=getpos(w,x);
	if (!bj)
	{
		for (int i=17;i>=0;i--)
			if (g[x][i]) x=g[x][i];
		getans(x);
		return;
 	} 
	else
	{	
		for (int i=17;i>=0;i--)
		{
			int y=g[x][i];
			if (!y||!getpos(w,y)&&y!=w||getpos(y,u)||getpos(y,v)) continue;
			if (calc(st[x][i],y)>=0) x=y;
		}
	}
	node a,b,c;
	if (x==u||x==v) x=f[x][0];
	a=(node){calc(size[son[x]],son[x]),getpos(u,son[x])?u:getpos(v,son[x])?v:0,son[x]};
	if (son[x]==u||son[x]==v||!son[x]) a.size=-inf;
	b=(node){calc(size[cs[x]],cs[x]),getpos(u,cs[x])?u:getpos(v,cs[x])?v:0,cs[x]};
	if (cs[x]==u||cs[x]==v||!cs[x]) b.size=-inf;
	c=(node){calc(size[ccs[x]],ccs[x]),getpos(u,ccs[x])?u:getpos(v,ccs[x])?v:0,ccs[x]};
	if (ccs[x]==u||ccs[x]==v||!ccs[x]) c.size=-inf;
	sort3(a,b,c);
	if (a.size==-inf)
	{
		getans(x);
		return;
	}
	if (getpos(a.iid,w)) w=a.id;
	solve(a.iid);
}
int main()
{
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	n=read();q=read(); 
	for (int i=1;i<n;i++)
		x=read(),y=read(),add(x,y),add(y,x),st[i][0]=inf;
	st[0][0]=inf;	
	dfs(1,0);
	for (int j=1;j<=17;j++)
		for (int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1],g[i][j]=g[g[i][j-1]][j-1];
			st[i][j]=min(st[i][j-1],st[g[i][j-1]][j-1]);
		}
	dfn[0]=leave[0]=size[0]=0;
	while (q--)
	{
		
		scanf("%d%d",&u,&v);ans=0;
		if (u==1||v==1)
		{
			printf("0\n");
			continue;
		}
		w=lca(u,v);
		if (u==w) v=0;
		else if (v==w) u=0;
		sum=n-size[u]-size[v];
		solve(1);
	}
	return 0;
} 
