#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 100100
#define ls(p) t[p].ls
#define rs(p) t[p].rs

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int T = 0; 
int n = 0, q = 0;
int a[MAXN] = { 0 };

int root = 1, cnt = 1;
struct Trange{
	int l, r;
	Trange() { l = r = 0; }
};
struct Tnode{
	int ls, rs;
	int val, tot;
	Trange a[3];
	Tnode() {
		tot = val = ls = rs = 0;
		a[1].l = a[1].r = a[2].l = a[2].r = 0;
	}
}t[MAXN];

void add(int val, int ll, int rr){
//	puts("in add");
//	printf("  val = %d ll = %d rr = %d\n", val, ll, rr);
	int p = root;
	while(1){
		if(!ls(p) and !rs(p)) break;
		if(val < t[p].val) p = ls(p);
		else if (val > t[p].val) p = rs(p);
		else break;
	}
	if(val == t[p].val) t[p].tot++, t[p].a[t[p].tot].l = ll, t[p].a[t[p].tot].r = rr;
	else{
//		puts("    in else"); 
		Tnode x;
		x.val = val, x.tot++, x.a[x.tot].l = ll, x.a[x.tot].r = rr;
		if(val < t[p].val) ls(p) = ++cnt, t[cnt] = x;
		else rs(p) = ++cnt, t[cnt] = x;
	}
}

int get(int val){                                    // get node by val
//	puts("    in get");
//	printf("      val = %d\n", val);
	int p = root;
	while(1){
//		printf("      p = %d\n", p);
//		printf("      t[p].ls = %d t[p].rs = %d\n", ls(p), rs(p));
		if(val < t[p].val) p = ls(p);
		else if(val > t[p].val) p = rs(p);
		else return p;
		if(!ls(p) and !rs(p)) return 0;
	}	
	return p;
}

void init(){
	t[root].val = ((n / 2) * n) - ((n / 2) * (n / 2) - (n / 2) + 1);
	if(n == 2) add(1, a[1], a[2]);
	else
		for(int i = 1; i <= n; i++){
			int k = (i * n) - (i * i - i + 1);
			if(i == 1) add(k, a[i], a[i + 1] - 1);
			else if(i == n) add(k, a[i - 1] + 1, a[i]);
			else add(k, a[i], a[i]), add(k - 1, a[i] + 1, a[i + 1] - 1);
		}
}

void clean(){
	for(int i = 1; i <= cnt; i++){
		t[i].val = t[i].ls = t[i].rs = t[i].tot = 0;
		t[i].a[0].l = t[i].a[0].r = t[i].a[1].l = t[i].a[1].r = 0;
	}
	root = cnt = 1;
}

int query(int k){
//	puts("in query");
//	printf("  k = %d\n", k); 
	int node = get(k);
//	printf("  node = %d\n", node);
	if(!node) return 0;
	else return t[node].a[1].r - t[node].a[1].l + t[node].a[2].r - t[node].a[2].l + 2;
}

signed main(){
	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);
	T = in;
	while(T--){
		n = in, q = in;
		for(int i = 1; i <= n; i++) a[i] = in;
//		printf("a : "); for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
		init();
//		printf("cnt = %d\n", cnt);
		for(int i = 1; i <= cnt; i++){
//			printf("t[%d].val = %d t[%d].ls = %d t[%d].rs = %d t[%d].tot = %d\n", i, t[i].val, i, t[i].ls, i, t[i].rs, t[i].tot);
//			printf("t[%d].a[1].l = %d t[%d].a[1].r = %d t[%d].a[2].l = %d t[%d].a[2].r = %d\n", i, t[i].a[1].l, i, t[i].a[1].r, i, t[i].a[2].l, i, t[i].a[2].r);
		}
		while(q--){
			int k = in;
			cout << query(k) << ' ';
		} puts("");
		clean();
	}
	return 0;
} 

/*
3
2 2
101 200
2 1
6 15
1 2 3 5 6 7
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
5 8
254618033 265675151 461318786 557391198 848083778
6 9 15 10 6 9 4 4294967300

*/
