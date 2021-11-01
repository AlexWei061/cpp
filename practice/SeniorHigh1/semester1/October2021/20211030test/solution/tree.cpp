#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,int sq){LL res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 400300
int n,fs[M],nt[M],to[M],d[M],tmp,lim[M],F[M];
LL ans,sum,b[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
int S[M],top,mx;
inline void DP(int x,int last){
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last) DP(to[i],x);
	top=0,sum=0,mx=0;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last) S[++top]=F[to[i]],sum+=F[to[i]],mx=max(mx,F[to[i]]);
	LL len=min(lim[x],d[x]);
	if(len==1){
		int con=min(sum,(LL)b[x]);
		F[x]=b[x]-con,ans-=con;
		return;
	}
	len=min(len-1,(LL)top);
	LL otsum=0;
	// debug(x)sp,debug(cnt)el;
	for(int i=1;i<=top;i++){
		if(S[i]>=b[x]&&len>=0) len--,ans-=b[x];
		if(S[i]<b[x]) otsum+=S[i];
	}
	if(len==-1){F[x]=0;return;}
	if(len==0){
		int con=min(otsum,b[x]);
		F[x]=b[x]-con,ans-=con;
		return;
	}
	if(len*b[x]>=otsum) F[x]=b[x],ans-=otsum;
	else if((len+1)*b[x]>=otsum) F[x]=(len+1)*b[x]-otsum,ans-=otsum;
	else F[x]=0,ans-=(len+1)*b[x];
}
inline LL solve(){
	n=read(),tmp=0,ans=0;
	for(int i=1;i<=n;i++) fs[i]=-1,d[i]=0,F[i]=0;
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x),d[x]++,d[y]++;
	for(int i=1;i<=n;i++) b[i]=read(),lim[i]=read(),ans+=b[i];
	// debug(ans)el;
	DP(1,0);
	return ans;

}
int main(){
	freopen("tree.in","r",stdin); 
	freopen("tree.out","w",stdout); 
	for(int Cas=read();Cas;--Cas) printf("%I64d\n",solve());
	return 0;
}
