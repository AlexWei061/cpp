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
int n,a[SZ],b[SZ];
char c[SZ]; string s;
int main()
{
	FO(weight)
	cin>>n;
	set<int> w;
	for(int i=0;i<n;++i) cin>>a[i],w.insert(a[i]);
	assert(w.size()==n);
	cin>>s;
	sort(a,a+n); a[n]=2e9;
	int r=-1;
	int op=0;
	for(int i=0;i<n;++i) if(i&&s[i]==s[i-1]) ++r;
	int l=r+1;
	for(int i=0;i<n;++i) {
		if(i&&s[i]==s[i-1]) {
			c[i]=op^=1; b[i]=a[r--];
		}
		else {
			c[i]=(s[i]=='R'); b[i]=a[l++];
			if(!i) op=(s[i]=='R');
		}
	}
	for(int i=0;i<n;++i) cout<<b[i]<<" "<<("LR"[c[i]])<<"\n";
}
