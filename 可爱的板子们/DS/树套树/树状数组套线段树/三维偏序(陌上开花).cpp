#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100
#define MAXK 200200

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int n = 0; int k = 0;
struct Tdata{
	int x, y, z;
	bool operator < (const Tdata &rhs) const {
		return x != rhs.x ? (x < rhs.x) : (y != rhs.y ? (y < rhs.y) : (z < rhs.z));
	}
	bool operator == (const Tdata & rhs) const {
		return (x == rhs.x) and (y == rhs.y) and (z == rhs.z);
	}
}data[MAXN];
int ans[MAXN] = { 0 };

struct Tnode{
    int dat;
    int ls, rs;
}t[MAXN << 5];
int tot = 0;

struct SegTree{

    inline void up(int p) { t[p].dat = t[t[p].ls].dat + t[t[p].rs].dat; }

    void update(int &p, int l, int r, int x, int val){
        if(!p) p = ++tot;
        if(l == r) { t[p].dat += val; return; }
        int mid = (l + r) >> 1;
        if(x <= mid) update(t[p].ls, l, mid, x, val);
        else update(t[p].rs, mid + 1, r, x, val);
        up(p);
    }

    int query(int p, int l, int r, int ql, int qr){
        if(!p) p = ++tot;
        if(ql <= l and r <= qr) return t[p].dat;
        int mid = (l + r) >> 1; int ans = 0;
        if(ql <= mid) ans += query(t[p].ls, l, mid, ql, qr);
        if(qr > mid) ans += query(t[p].rs, mid + 1, r, ql, qr);
        return ans;
    }

}seg;

struct BIT{

    int root[MAXN << 2];

    inline int lowbit(int x) { return x & -x; }

    void add(int x, int y, int val){
        for(; x <= k; x += lowbit(x)) seg.update(root[x], 1, k, y, val);
    }

    int query(int x, int y){
        int ans = 0;
        for(; x; x -= lowbit(x)) ans += seg.query(root[x], 1, k, 1, y);
        return ans;
    }

}T;

int main(){
    n = in; k = in;
    for(int i = 1; i <= n; i++) data[i].x = in, data[i].y = in, data[i].z = in;
    sort(data + 1, data + n + 1); int sum = 1;
    for(int i = 1; i <= n; i++) {
        if(data[i] == data[i + 1]) { sum++; continue; }
        T.add(data[i].y, data[i].z, sum);
        int res = T.query(data[i].y, data[i].z);
        ans[res] += sum; sum = 1;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
