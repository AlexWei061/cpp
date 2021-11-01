#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 3020
using namespace std;
int read(){
    int nm=0,fh=1;char cw=getchar();
    for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
    for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
    return nm*fh;
}
int n,m,fs[M],nt[M<<1],to[M<<1],len[M<<1];
int ans,F[M][M],B[M][M],C[M][M],dst,tmp,u,v,sz[M];
void update(int &x,int y){x=min(x,y);}
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp]=y,len[tmp++]=dst;}
void DP(int x,int last){
    sz[x]=1,F[x][1]=C[x][1]=B[x][1]=0;
    for(int i=fs[x];i!=-1;i=nt[i]){
        if(to[i]==last) continue;
        int v=to[i]; DP(v,x);
        for(int k=sz[x];k>0;k--){
            for(int j=sz[v];j>0;j--){
                update(B[x][j+k],B[v][j]+B[x][k]+(len[i]<<1));
                update(F[x][j+k],min(B[v][j]+F[x][k]+len[i],F[v][j]+B[x][k])+len[i]);
                update(C[x][j+k],min(min(C[x][k]+B[v][j],C[v][j]+B[x][k])+len[i],F[x][k]+F[v][j])+len[i]);
            }
        }
        sz[x]+=sz[v];
    }
    update(ans,min(min(C[x][m],B[x][m]),F[x][m]));
}
int main(){
	freopen("set.in","r",stdin); 
	freopen("set.out","w",stdout); 
    n=read(),m=read(),memset(&ans,0x7f,sizeof(int));
    memset(fs,-1,sizeof(fs)),memset(F,0x7f,sizeof(F));
    memset(C,0x7f,sizeof(C)),memset(B,0x7f,sizeof(B));
    for(int i=1;i<n;i++) u=read(),v=read(),dst=read(),link(u,v),link(v,u);
    DP(1,0),printf("%d\n",ans);
    return 0;
}
