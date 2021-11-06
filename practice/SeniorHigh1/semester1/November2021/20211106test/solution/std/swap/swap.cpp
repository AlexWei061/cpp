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
#define U 26
#define SZ 666666
const int MOD=998244352;
int f[3005][2][3005],n,k,mi[SZ],fac[U]; Edg
void dfs(int x,int fa=0) {
	for esb(x,e,b) if(b!=fa) dfs(b,x);
	static int c[2][3005][U+1],g[2][3005][U+1]; int mx=0;
	memset(c[0][0],0,sizeof c[0][0]);
	memset(c[1][0],0,sizeof c[1][0]);
	c[1][0][1]=1; c[0][0][0]=1;
	for esb(x,e,b) if(b!=fa) {
		int tx=mx+mi[b]+1;
		for(int j=0;j<=tx;++j)
			memset(g[0][j],0,sizeof g[0][0]),
			memset(g[1][j],0,sizeof g[1][0]);
		int C,F;
		for(int o=0;o<2;++o)
			for(int j=0;j<=mx;++j)
				for(int s=0;s<U;++s) if(C=c[o][j][s])
					for(int k=0;k<=mi[b];++k) {
						if(F=f[b][0][k])
							g[o][j+k][s]=(g[o][j+k][s]+(ll)C*F)%MOD;
						if(F=f[b][1][k])
							g[o][j+k+1][s+1]=(g[o][j+k+1][s+1]+(ll)C*F)%MOD;
					}
		mx=tx;
		for(int j=0;j<=tx;++j)
			memcpy(c[0][j],g[0][j],sizeof g[0][0]),
			memcpy(c[1][j],g[1][j],sizeof g[1][0]);
	}
	mi[x]=mx;
	for(int o=0;o<2;++o)
		for(int j=0,C;j<=mx;++j)
			for(int k=0;k<U;++k) if(C=c[o][j][k])
				(f[x][o][j]+=C*(ll)fac[k]%MOD)%=MOD;
}
int main()
{
	FO(swap)
	fac[0]=1;
	for(int i=1;i<U;++i)
		fac[i]=fac[i-1]*(ll)i%MOD;
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1);
	printf("%d\n",f[1][0][k]);
	cerr<<clock()<<"ms\n";
}

