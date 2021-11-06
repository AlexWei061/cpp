#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,w,a[SZ],su,q[SZ];
short f[405][405][405];
int c[3];
int main()
{
	FO(pack)
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),
		q[i]=q[i-1]+a[i],
		su+=a[i],++c[a[i]];
	if(su<=w) {
		puts("0"); return 0;
	}
	memset(f,127/3,sizeof f);
	f[0][0][0]=0;
	auto upd=[&](short&a,int b) {
		if(a>b)a=b;
	};
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
			for(int k=0;j+k<=i;++k) if(f[i][j][k]<=8000) {
				int tw=q[i]-j-k*2+f[i][j][k];
				if(tw%w+a[i+1]<=w)
					upd(f[i+1][j][k],f[i][j][k]);
				else
					upd(f[i+1][j][k],f[i][j][k]+w-tw%w);
				if(a[i+1]==1)
					upd(f[i+1][j+1][k],f[i][j][k]);
				if(a[i+1]==2)
					upd(f[i+1][j][k+1],f[i][j][k]);
			}
	pii ans(2e9,2e9);
	for(int j=0;j<=n;++j)
		for(int k=0;j+k<=n;++k) if(f[n][j][k]>=0) {
			int tw=q[n]-j-k*2+f[n][j][k],K=k,J=j;
			while(K) {
				if(tw%w+2<=w) --K,tw+=2;
				else if(J) --J,tw+=1;
				else --K,tw+=3;
			}
			while(J) --J,tw+=1;
			ans=min(ans,pii((tw+w-1)/w,j+k));
		}
	cout<<ans.se<<"\n";
}

