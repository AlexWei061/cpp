#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

typedef long long ll;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
      if (k&1) ans=ans*x%MOD;
      x=x*x%MOD;
      k>>=1;
  }
  return ans;
}

ll facd[5000005],facv[5000005];

void pre(int n) {
  facd[0]=1;
  for(int i=1;i<=n;i++) facd[i]=facd[i-1]*i%MOD;
  facv[n]=pow_mod(facd[n],MOD-2);
  for(int i=n-1;i>=0;i--) facv[i]=facv[i+1]*(i+1)%MOD;
} 

inline ll C(int n,int m) {
  return (n<m)?0:facd[n]*facv[m]%MOD*facv[n-m]%MOD;
}

ll f[5000005],g[5000005];

int main() {
  freopen("game.in","r",stdin); 
  freopen("game.out","w",stdout);
  pre(5e6);
  int cases;
  scanf("%d",&cases);
  for(;cases;cases--) {
      int n,m;
    ll p,q;
      scanf("%d%d%lld%lld",&n,&m,&p,&q);
      n--;
      p=p*pow_mod(100,MOD-2)%MOD;
      q=q*pow_mod(100,MOD-2)%MOD;
      ll inv=pow_mod(1LL-(1LL-p+MOD)*(1LL-q+MOD)%MOD+MOD,MOD-2);
      ll v00=inv*(1LL-q+MOD)%MOD*p%MOD;
      ll v01=inv*q%MOD;
      ll v10=inv*p%MOD;
      ll v11=inv*(1LL-p+MOD)%MOD*q%MOD;
      if (!n) {
          printf("%lld\n",v10*pow_mod(v00,m-1)%MOD);
          continue;
      }
      f[0]=1;
      for(int i=1;i<=n;i++) f[i]=f[i-1]*v11%MOD;
      g[0]=1;
      for(int i=1;i<=m;i++) g[i]=g[i-1]*v00%MOD;
      ll ans=v10*pow_mod(v00,m-1)%MOD,s1=v10,s2=0;
      for(int i=0;i<n;i++) s2=(s2+f[i])%MOD;
      inv=pow_mod(1LL-v11+MOD,MOD-2);
      for(int i=2;i<=n+m;i++) {
          int u=(i>>1),v=i-u;
          ll w=s1*s2%MOD*C(m-1,v-1)%MOD*g[m-v]%MOD;
          if (i&1) w=w*v10%MOD; else w=w*v11%MOD;
          ans=(ans+w)%MOD;
          if (i&1) {
              if (u>=n) break;
              s1=s1*v10%MOD;
              s2=((s2-C(n-1,u-1)*f[n-u]-C(n-1,u)*f[n-u])%MOD+MOD)*inv%MOD;
              u++;
          }
        else {
            if (v>=m) break;
            s1=s1*v01%MOD;
            v++;
        }
      }
    printf("%lld\n",ans);
  }
  return 0;
}
