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
int cnt[MAXN] = { 0 };

struct Tdata{
    int x, y, z;
    int operator < (const Tdata &o) const {
        return x != o.x ? (x < o.x) : (y != o.y ? (y < o.y) : (z < o.z));
    }
    int operator == (const Tdata &o) const {
        return (x == o.x) and (y == o.y) and (z == o.z);
    }
}data[MAXN];

struct SegTree{
    
	struct Tnode{
        int val; Tnode *ch[2];
        Tnode(int val = 0) : val(val) {
            ch[0] = ch[1] = NULL;
        }
    }*rt;
    SegTree() { rt = NULL; }
    
    void update(Tnode *&p, int pos, int val, int nl, int nr) {
        if (!p) p = new Tnode();
        if (nl == nr) { p->val += val; return; }
        int mid = (nl + nr) >> 1;
        if (pos <= mid) update(p->ch[0], pos, val, nl, mid);
        else update(p->ch[1], pos, val, mid + 1, nr);
        p->val = (p->ch[0] ? p->ch[0]->val : 0) + (p->ch[1] ? p->ch[1]->val : 0);
    }
    
    int query(Tnode *p, int l, int r, int nl, int nr) {
        if (!p) return 0;
        if (l == nl and r == nr) return p->val;
        int mid = (nl + nr) >> 1;
        if (r <= mid) return query(p->ch[0], l, r, nl, mid);
        else if (l > mid) return query(p->ch[1], l, r, mid + 1, nr);
        return query(p->ch[0], l, mid, nl, mid) + query(p->ch[1], mid + 1, r, mid + 1, nr);
    }
}tree[MAXK];

struct BIT{
	
	int lowbit(int x) { return x & (-x); }
	
	void add(int x, int y, int val) {
	    for (; x <= k; x += lowbit(x)) 
	        tree[x].update(tree[x].rt, y, val, 1, k);
	}
	
	int query(int x, int y) {
	    int ans = 0;
	    for (; x; x -= lowbit(x)) ans += tree[x].query(tree[x].rt, 1, y, 1, k);
	    return ans;
	}
	
}T;

int main() {
    n = in; k = in;
    for (int i = 1; i <= n; i++) { data[i].x = in; data[i].y = in; data[i].z = in; }
    sort(data + 1, data + n + 1); int sum = 1;
    for (int i = 1; i <= n; i++) {
        if (data[i + 1] == data[i]) { sum++; continue; }
        T.add(data[i].y, data[i].z, sum);
        int res = T.query(data[i].y, data[i].z);
        cnt[res] += sum; sum = 1;
    }
    for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
    return 0;
}