#include<bits/stdc++.h>
using namespace std;

const int M=105;
int n,ans[M],bj=0,re[M];
double S,R,a[M],x,y,dis,vis[M],mi=1e25,suf[M];

struct node{
	double val;
	int id;
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
}b[M];

int fl=0,be;

void dfs(int now,double d){
	if(d>=dis){
		mi=d;return;
	}
	if(now==n+1) return ;
	if(clock()-be>=500) fl=1;
	if(fl) return ;
	if(d+suf[now]<dis) return;
	if(d+a[now]>mi&&d+a[now]>dis){
		;
	}
	else{
		vis[now]=1;dfs(now+1,d+a[now]);vis[now]=0;
	}
	dfs(now+1,d);
}

inline bool cmp(double x,double y){
	return x>y;
}
vector <int> Ans;

int main(){
	freopen("gogogo.in","r",stdin);
	freopen("gogogo.out","w",stdout);
    be=clock();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],S+=a[i],b[i].val=a[i],b[i].id=i;
	cin>>R>>x>>y;
	dis=sqrt(x*x+y*y);dis-=R;
	if(S<=dis){
		printf("%0.3lf\n",S);
		return 0;
	}
	double SS=0;
	for(int i=0;i<=n;i++){
		SS+=a[i];
		for(int j=i+1;j<=n;j++){
			if(SS+a[j]>=dis&&SS+a[j]<mi){
				mi=SS+a[j];
				for(int k=1;k<=i;k++) ans[k]=1;
				for(int k=i+1;k<=n;k++) if(k==j) ans[k]=1;else ans[k]=0;
			}
		}
	}

	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
	for(int i=1;i<=n;i++) re[i]=b[i].id;
	dfs(1,0);
	printf("%0.3lf\n",mi);
	return 0;
}
