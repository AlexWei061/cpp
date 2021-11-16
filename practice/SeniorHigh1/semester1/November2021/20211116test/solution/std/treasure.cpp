#include<cstdio>
#define N 100005
#define M 105
#define K 100005
using namespace std;
int n,m,k,cnt,f[N][M],g[N][M],a[N][M];
long long ans;
struct BIT
{
	int v[M];
	void modify(int x)
	{
		if (!x) ++v[0]; 
		for (;x<M && x;x+=x&-x) ++v[x];
	}
	int query(int x)
	{
		int res=0;
		for (;x;x-=x&-x) res+=v[x];
		return res+v[0];
	}
} s[K*3];
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d%d\n",&n,&m,&k);
	for (int i=1;i<=n;++i,scanf("\n"))
		for (int j=1;j<=m;++j)
			if (getchar()=='$')
				++f[i][j],++g[i][j],++cnt;
	for (int i=1;i<=n;++i) for (int j=1;j<=m;++j)
		f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
	for (int i=n;i;--i) for (int j=m;j;--j)
		g[i][j]+=g[i+1][j]+g[i][j+1]-g[i+1][j+1];
	for (int i=0;i<=n;++i) for (int j=0;j<=m;++j)
		a[i][j]=f[i][j]-g[i+1][j+1];
	//if (cnt>100000) return printf("?"),0;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<m;++j) 
			s[a[i-1][j]+2*cnt].modify(j);
		for (int j=1;j<=m;++j)
			ans+=s[a[i][j]-k+2*cnt].query(j-1);
	}
	printf("%lld",ans);
}
