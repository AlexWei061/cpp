#include<bits/stdc++.h>
#define Maxn 500100
using namespace std;
namespace DEBUG {
	inline void cerr_out(){cerr<<'\n';}
	template<typename Head,typename... Tail>
	inline void cerr_out(Head H,Tail... T){cerr<<' '<<H,cerr_out(T...);}
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?EOF:*S++)
namespace get_out
{
	char B[1<<20],*S=B,*T=B;
	char op;
	inline void read_(int &x)
	{
		x=0;
		int fi(1);
		op=getchar();
		while((op<'0'||op>'9')&&op!='-') op=getchar();
		if(op=='-') op=getchar(),fi=-1;
		while(op>='0'&&op<='9') x=(x<<1)+(x<<3)+(op^48),op=getchar();
		x*=fi;
		return;
	}
	inline void read_(long long &x)
	{
		x=0;
		int fi(1);
		op=getchar();
		while((op<'0'||op>'9')&&op!='-') op=getchar();
		if(op=='-') op=getchar(),fi=-1;
		while(op>='0'&&op<='9') x=(x<<1)+(x<<3)+(op^48),op=getchar();
		x*=fi;
		return;
	}
	inline void read_(double &x)
	{
		x=0.0;
		float fi(1.0),sm(0.0);
		op=getchar();
		while((op<'0'||op>'9')&&op!='-') op=getchar();
		if(op=='-') op=getchar(),fi=-1.0;
		while(op>='0'&&op<='9') x=(x*10.0)+(op^48),op=getchar();
		if(op=='.') op=getchar();
		int rtim=0;
		while(op>='0'&&op<='9') sm=(sm*10.0)+(op^48),++rtim,op=getchar();
		while(rtim--) sm/=10.0;
		x+=sm,x*=fi;
		return;
	}
	inline void read_(string &s)
	{
		char c(getchar());
		s="";
		while(!isgraph(c)&&c!=EOF) c=getchar();
		for(;isgraph(c);c=getchar()) s+=c;
	}
	inline void read_(char &c)
	{
		for(c=op;c==' '||c=='\n'||c=='\r'||c=='\t';c=getchar());
		op=c;
	}
	
	template<typename Head,typename ...Tail>
	inline void read_(Head& h,Tail&... t)
	{read_(h),read_(t...);}
	
	inline void write_(){}
	inline void postive_write(unsigned x)
	{
		if(x>9) postive_write(x/10);
		putchar(x%10|'0');
	}
	inline void postive_write(unsigned long long x)
	{
		if(x>9) postive_write(x/10);
		putchar(x%10|'0');
	}
	inline void postive_write(int x)
	{
		if(x>9) postive_write(x/10);
		putchar(x%10|'0');
	}
	inline void postive_write(long long x)
	{
		if(x>9) postive_write(x/10);
		putchar(x%10|'0');
	}
	inline void postive_write(short x)
	{
		if(x>9) postive_write(x/10);
		putchar(x%10|'0');
	}
	inline void write_(const char* ss) {while(*ss) putchar(*ss++);}
	inline void write_(char c) {putchar(c);}
	inline void write_(string s) {for(unsigned i=0;i<s.size();++i) putchar(s[i]);}
	inline void write_(short x)
	{
		if(x<0) putchar('-'),postive_write(-x);
		else postive_write(x);
	}
	inline void write_(int x)
	{
		if(x<0) x=-x,putchar('-');
		postive_write(x);
	}
	inline void write_(long long x)
	{
		if(x<0) x=-x,putchar('-');
		postive_write(x);
	}
	inline void write_(unsigned x) {postive_write(x);}
	inline void write_(ull x) {postive_write(x);}
	
	template<typename Head,typename ...Tail>
	inline void write_(Head h,Tail ...t) {write_(h),write_(t...);}
}
using get_out::read_;
using get_out::write_;
vector<int>cnt[Maxn<<1];
int n,F,m,fa[Maxn<<1];
int a[Maxn<<1],b[Maxn<<1],ans_[Maxn<<1];
struct ques
{
	int l,r,id;
	int bl;
}q[Maxn<<1];
inline bool cmp(ques &a,ques &b)
{
	return a.bl!=b.bl?a.bl<b.bl:a.r<b.r;
}
int main()
{
	read_(n,m);
	F=pow(n,0.45)+5;
	for(register int i=1;i<=n;i++) read_(a[i]);
	for(register int i=1;i<=n;i++) read_(b[i]);
	for(register int i=1,k;i<=n;i++)
	{
		cnt[i].emplace_back(-0x7ffffff);
		k=i-1;
		while(k&&((a[k]==a[i])||((a[k]^a[i])&&b[k]<=b[i])))
			k=fa[k];
		cnt[fa[i]=k].emplace_back(i);
	}
	for(register int i=1;i<=m;i++)
	{
		read_(q[i].l,q[i].r);
		q[i].id=i,q[i].bl=q[i].l/F;
	}
	sort(q+1,q+m+1,cmp);
//	cerr<<clock();
	int l=1,r=1,ans=1;
	for(register int i=1;i<=m;i++)
	{
		while(q[i].r>r)
			ans+=(fa[++r]<l?1:0);
		while(q[i].l<l)
		{
			l--,ans++;
			vector<int>::iterator t1=upper_bound(cnt[l].begin(),cnt[l].end(),l);
			vector<int>::iterator t2=upper_bound(cnt[l].begin(),cnt[l].end(),r)-1;
			if(t1!=cnt[l].end()&&t2!=cnt[l].begin())
				ans-=(t2-t1+1);
		}
		while(q[i].r<r)
			ans-=(fa[r--]<l?1:0);
		while(q[i].l>l)
		{
			vector<int>::iterator t1=upper_bound(cnt[l].begin(),cnt[l].end(),l);
			vector<int>::iterator t2=upper_bound(cnt[l].begin(),cnt[l].end(),r)-1;
			if(t1!=cnt[l].end()&&t2!=cnt[l].begin())
				ans+=(t2-t1+1);
			l++,ans--;
		}
		ans_[q[i].id]=ans;
	}
	for(register int i=1;i<=m;i++) write_(ans_[i],'\n');
}
