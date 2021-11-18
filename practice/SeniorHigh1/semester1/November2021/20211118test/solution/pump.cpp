#include<bits/stdc++.h>
#define inf 9999999
using namespace std;
inline int read()//快读
{
	int ret=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return w*ret;
}
int n,m;
int tot=1;
struct node{
	int v,c;
	bool flag;
}edge[2010];
int nxt[2010];
int hd[1010];
inline void add_edge(int u,int v,int c)//前向星
{
	edge[tot].v=v,edge[tot].c=c;
	nxt[tot]=hd[u];
	hd[u]=tot++;
}
struct node2{
	int u,v,c,f;
}a[1010];
bool cmp(node2 a,node2 b)//将边按流量排序（实际没什么卵用）
{
	return a.f<b.f;
}
struct node3            //Dijkstra专用堆+运算符重载
{
	int pos,num;
	friend bool operator < (node3 a,node3 b)
	{
		return a.num>b.num;
	}
};

long double ans=0;
priority_queue<node3> q;
int dis[1010];
bool book[1010];

inline void init(int limit)//按照流量限制初始化并建图
{
	tot=1;
	memset(edge,0,sizeof(edge));
	memset(nxt,0,sizeof(nxt));
	memset(hd,0,sizeof(hd));
	memset(book,0,sizeof(book));
	for(int i=1;i<=n;i++) dis[i]=(i==1)? 0:inf;
	for(int i=1;i<=m;i++)
	if(a[i].f>=limit)
	{
		add_edge(a[i].u,a[i].v,a[i].c);
		add_edge(a[i].v,a[i].u,a[i].c);
	}
}

void Dijkstra() //Dijkstra
{
	q.push({1,0});
	while(!q.empty())
	{
		int x=q.top().pos;
		q.pop();
		if(book[x]) continue;
		book[x]=1;
		for(int i=hd[x];i;i=nxt[i])
		if(dis[edge[i].v]>dis[x]+edge[i].c)
		{
			dis[edge[i].v]=dis[x]+edge[i].c;
			q.push({edge[i].v,dis[edge[i].v]});
		}
	}
}

int main()
{
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].c=read(),a[i].f=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=1000;i++)
	{
		init(i);
		Dijkstra();
		ans=max(ans,(long double)i/(long double)dis[n]);
	}
	ans*=(long double)1000000;
	ans=floor(ans);
	printf("%lld\n",(long long)ans);
	return 0;
}
