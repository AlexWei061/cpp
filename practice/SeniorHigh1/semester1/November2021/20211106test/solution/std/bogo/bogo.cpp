#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
ll qp(ll a,ll b) {
	ll x=1; a%=MOD;
	while(b) {
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
int n,a[233333],c[1234567];
int main() {
	FO(bogo)
	scanf("%d",&n);
	ll x=1,y=1;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),y=y*(++c[a[i]])%MOD,x=x*i%MOD;
	if(is_sorted(a+1,a+1+n)) x=0;
	printf("%d\n",int(x*qp(y,MOD-2)%MOD+MOD)%MOD);
}

