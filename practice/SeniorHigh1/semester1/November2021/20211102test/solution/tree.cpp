#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int f=1,g=0;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
   	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
   	return f*g;
}
const int N=500005;
int size,fir[N],n,k,depth[N],hs[N],cnt;
struct node{int f[20][2];}b[N],a[N],ta,tb;
node operator+(node a,int b){
	for (int i=0;i<20;i++)
	{a.f[i][b&1]++;b>>=1;}
	return a;
}
void operator+=(node &a,node b){
	for (int i=0;i<20;i++)
	{a.f[i][0]+=b.f[i][0];a.f[i][1]+=b.f[i][1];}
}
node operator+(node a,node b){a+=b;return a;}
node operator-(node a,node b){
	for (int i=0;i<20;i++)
	{a.f[i][0]-=b.f[i][0];a.f[i][1]-=b.f[i][1];}
	return a;
}
ll operator*(node &a,node &b){
	ll ans=0;
	for (int i=0;i<20;i++)
	ans+=((ll)a.f[i][0]*b.f[i][1]+(ll)a.f[i][1]*b.f[i][0])<<i;
	return ans;
}
node *f[N];
long long ans;
struct edge{int u,v,nex;}e[N*2];
void add(int u,int v){e[++size]=(edge){u,v,fir[u]};fir[u]=size;}
void clear(){
	memset(fir,0,sizeof(fir));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(depth,0,sizeof(depth));
	memset(hs,0,sizeof(hs));
}
void build(int x,int fa){
	depth[x]=1;
	for (int i=fir[x];i;i=e[i].nex)
	if (e[i].v!=fa){
		int y=e[i].v;build(y,x);
		if (depth[y]+1>depth[x]){
			depth[x]=depth[y]+1;
			hs[x]=y;
		}
	}
}
void cre(int x){f[x]=b+cnt;cnt+=depth[x];}
node calc(int x,int i){
	if (i<0) return f[x][0];
	return (depth[x]<=i) ? b[0] : f[x][i];
}
node& calc(int x,int l,int r,node &a){return a=calc(x,l)-calc(x,r+1);}
void merge(int x,int y){
	for (int i=0;i<depth[y];i++)
	ans+=calc(y,i,i,ta)*calc(x,0,k-i-1,tb);
	for (int i=0;i<depth[y];i++)
	f[x][i+1]+=f[y][i];
	f[x][0]+=f[y][0];
}
void dp(int x,int fa){
	if (hs[x]){
		f[hs[x]]=f[x]+1;
		dp(hs[x],x);
		f[x][0]=f[x][1]+a[x];
		ans+=a[x]*calc(x,0,k,ta);
	}
	else f[x][0]=a[x];
	for (int i=fir[x];i;i=e[i].nex)
	if ((e[i].v!=fa)&&(e[i].v!=hs[x])){
		int y=e[i].v;cre(y);dp(y,x);
		merge(x,y);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();k=read();
	size=ans=0;cnt=1;
	//clear();
	for (int i=1;i<=n;i++){
		int x=read();
		a[i]=a[i]+x;
	}
	for (int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	build(1,0);cre(1);
	dp(1,0);
	printf("%lld\n",ans);
	return 0;
}
