#include <bits/stdc++.h>

using namespace std;
namespace IO{
    char buf[2000020],*cur=buf+2000020;
    inline char getc(){
        (cur==buf+2000020)?fread(cur=buf,1,2000020,stdin):0;
        return *cur++;
    }
    char buff[2000020],*curr=buff;
    inline void flush(){
        fwrite(buff,1,curr-buff,stdout);
    }
    inline void putc(const char &ch){
        (curr==buff+2000020)?fwrite(curr=buff,1,2000020,stdout):0;
        *curr++=ch;
    }
  
    inline void read(int &x){
        x=0;char ch=getc();int f=1;
        while(ch<'0'||ch>'9'){
            if(ch=='-')f=-1;
            ch=getc();
        }
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getc();
        }
        x*=f;
    }
 
    char st[60];int tp;
    void PT(int x){
        if(x==0)putc('0');
        else{
            while(x>0){
                st[++tp]=x%10+'0';
                x/=10;
            }
        }
        while(tp)putc(st[tp--]);
    }
}
using IO::getc;
using IO::putc;
using IO::read;
using IO::PT;
const int N = 5e5 + 5;
int n, m, a[N], b[N];

struct segmentTree {
	#define lc(x) (x << 1)
	#define rc(x) (x << 1 | 1)
	int mxa[N << 2], mxb[N << 2], tga[N << 2], tgb[N << 2];
	void pup(int p) {
		mxa[p] = max(mxa[lc(p)], mxa[rc(p)]);
		mxb[p] = max(mxb[lc(p)], mxb[rc(p)]);
	}
	void pdown(int p) {
		if(tga[p]) {
			mxa[lc(p)] += tga[p], mxa[rc(p)] += tga[p];
			tga[lc(p)] += tga[p], tga[rc(p)] += tga[p];
			tga[p] = 0;
		}
		if(tgb[p]) {
			mxb[lc(p)] += tgb[p], mxb[rc(p)] += tgb[p];
			tgb[lc(p)] += tgb[p], tgb[rc(p)] += tgb[p];
			tgb[p] = 0;
		}
	}
	void build(int l, int r, int p) {
		if(l == r) {
			mxa[p] = a[l], mxb[p] = b[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lc(p)), build(mid + 1, r, rc(p));
		pup(p);
	}
	void modify(int l, int r, int p, int x, int y, int k, int* mx, int* tg) {
		if(l >= x && r <= y) {
			mx[p] += k, tg[p] += k;
			return;
		}
		pdown(p);
		int mid = (l + r) >> 1;
		if(x <= mid) modify(l, mid, lc(p), x, y, k, mx, tg);
		if(y > mid) modify(mid + 1, r, rc(p), x, y, k, mx, tg);
		pup(p);
	}
	int query(int l, int r, int p, int x, int y, int* mx) {
		if(l >= x && r <= y) return mx[p];
		pdown(p);
		int mid = (l + r) >> 1, ret = INT_MIN;
		if(x <= mid) ret = max(ret, query(l, mid, lc(p), x, y, mx));
		if(y > mid) ret = max(ret, query(mid + 1, r, rc(p), x, y, mx));
		return ret;
	}
	#undef lc
	#undef rc
} st; 

void modify(char op, int l, int r, int d) {
	if(op == 'A') st.modify(1, n, 1, l, r, d, st.mxa, st.tga);
	else st.modify(1, n, 1, l, r, d, st.mxb, st.tgb);
}

void query(int x, int y) {
	int ans = INT_MAX;
	int l = x, r = y, mid, mxa, mxb;
	while(l <= r) {
		mid = (l + r) >> 1;
		mxa = st.query(1, n, 1, x, mid, st.mxa);
		mxb = st.query(1, n, 1, mid + 1, y, st.mxb);
		ans = min(ans, max(mxa, mxb));
//		debug(l, mid, r, ans, mxa, mxb);
		if(mxa >= mxb) r = mid - 1;
		else l = mid + 1;
	}
	ans = min(ans, st.query(1, n, 1, x, y, st.mxb));
	if(ans < 0) putc('-'), ans = -ans;
	PT(ans), putc('\n');
}

int main() {
	freopen("girl.in", "r", stdin);
	freopen("girl.out", "w", stdout);
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) read(b[i]);
	st.build(1, n, 1);
	char op; int l, r, d;
	for(int i = 1; i <= m; i++) {
		op = getc();
		while(op != 'A' && op != 'B') {
			op = getc();
		}
		read(l), read(r), read(d);
		modify(op, l, r, d);
		read(l), read(r);
		query(l, r);
//		if(i % 100 == 0) debug(i);
	}

	IO::flush();//Don't forget to do it!!!
	return 0;
}
