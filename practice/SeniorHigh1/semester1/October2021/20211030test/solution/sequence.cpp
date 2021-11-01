#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define INF 10000000000000ll
#define M 300020
using namespace std;
namespace IO{
    const int BS=(1<<20)+5; int Top=0;
    char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
    char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
    void flush(){fwrite(OT,1,OS-OT,stdout);}
    void Putchar(char c){*OS++ =c;if(OS==fin)flush(),OS=OT;}
    void write(LL x){
        if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
        while(x) SS[++Top]=x%10,x/=10;
        while(Top) Putchar(SS[Top]+'0'),--Top;
    }
    int read(){
        int nm=0,fh=1; char cw=Getchar();
        for(;!isdigit(cw);cw=Getchar()) if(cw=='-') fh=-fh;
        for(;isdigit(cw);cw=Getchar()) nm=nm*10+(cw-'0');
        return nm*fh;
    }
}
using namespace IO;
int n,m,p[M];
LL H[M],G[M],F[M],S[M],top,D[M],P[M];
LL X[M],Y[M];
#define calc(b,a) x[b]-S[a-1]+S[b]+((LL)(a-b-1)*(LL)(a-b)>>1)
#define conv(a,b,c) ((double)(Y[b]-Y[a])/(double)(X[b]-X[a])>(double)(Y[c]-Y[b])/(double)(X[c]-X[b]))
#define Transl(b,a) G[a+1]-S[a]+S[b]+F[b]+((LL)(a-b)*(LL)(a-b+1)>>1)
#define Transr(b,a) F[a-1]-S[a]+S[b]+G[b]+((LL)(b-a)*(LL)(b-a+1)>>1)
void init(LL *x){
    S[top=1]=0,Y[0]=X[0]=S[0]=0;
    for(LL i=1;i<=n+1;i++) S[i]=S[i-1]+p[i];
    for(LL i=0;i<=n+1;i++){
        while(top>1&&calc(P[top-1],i)>=calc(P[top],i)) top--;
        if(top) x[i]=calc(P[top],i);else x[i]=0;
        X[i]=i,Y[i]=x[i]+S[i]+((i*i+i)>>1);
        while(top>1&&!conv(P[top-1],P[top],i)) top--; P[++top]=i;
    }
}
void solve(int l,int r){
    if(l==r){H[l]=max(H[l],F[l-1]+G[r+1]-p[l]+1);return;}
    int mid=((l+r)>>1); solve(l,mid),solve(mid+1,r);
    top=S[l-1]=S[r+1]=X[l-1]=X[r+1]=Y[l-1]=Y[r+1]=0;
    D[l-1]=D[r+1]=-INF; top=0;
     
    for(int i=l;i<=r;i++) D[i]=-INF,S[i]=S[i-1]+p[i]; top=0;
    for(int i=l-1;i<=mid;i++){
        X[i]=i,Y[i]=F[i]+S[i]+(((LL)i*(LL)i+(LL)i)>>1);
        while(top>1&&!conv(P[top-1],P[top],i)) top--; P[++top]=i;
    }
    for(int i=mid+1;i<=r;i++){
        while(top>1&&Transl(P[top-1],i)>=Transl(P[top],i)) top--;
        D[i]=Transl(P[top],i);
    }
    for(int i=r;i>mid;i--) D[i]=max(D[i+1],D[i]),H[i]=max(H[i],D[i]);
     
    for(int i=r;i>=l;i--) S[i]=S[i+1]+p[i]; top=0;
    for(int i=r+1;i>mid;i--){
        X[i]=i,Y[i]=G[i]+S[i]+(((LL)i*(LL)i+(LL)i)>>1);
        while(top>1&&!conv(i,P[top],P[top-1])) top--; P[++top]=i;
    }
    for(int i=mid;i>=l;i--){
        while(top>1&&Transr(P[top-1],i)>=Transr(P[top],i)) top--;
        D[i]=Transr(P[top],i);
    }
    for(int i=l;i<=mid;i++) D[i]=max(D[i-1],D[i]),H[i]=max(H[i],D[i]);
}
int main(){
	freopen("sequence.in","r",stdin); 
	freopen("sequence.out","w",stdout); 
    n=read(); for(int i=1;i<=n;i++) p[i]=read(),H[i]=-INF;
    init(F),reverse(p+1,p+n+1),init(G),reverse(p+1,p+n+1);
    reverse(G+1,G+n+1),G[0]=G[n+1],G[n+1]=0; solve(1,n);
    for(int TT=read();TT;TT--,Putchar('\n')){
        LL pos=read(),K=read();
        write(max(F[pos]+G[pos],H[pos]+p[pos]-K));
    } flush(); return 0;
}
