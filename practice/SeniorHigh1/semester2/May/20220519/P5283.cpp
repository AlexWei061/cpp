#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 20002000

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int a[MAXN] = { 0 };
int s[MAXN] = { 0 };
int n = 0; int k = 0;

int tot = 0;
int trie[MAXN][5] = { 0 };
int size[MAXN] = { 0 };

void build(int x) {
    int p = 0;
    for(int i = 31; i >= 0; i--){
        int ch = (x >> i) & 1; size[p]++;
        if(!trie[p][ch]) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    size[p]++;
}

int query(int x, int rk){
	int p = 0; int ans = 0;
	for(int i = 31; i >= 0; i--){
		int ch = (x >> i) & 1;
		if(!trie[p][ch ^ 1]) p = trie[p][ch];                                       // 如果没有相反的直接跑 
		else if(rk <= size[trie[p][ch ^ 1]]) p = trie[p][ch ^ 1], ans |= 1ll << i;    // 相反的子树大小大于等于当前值 
		else rk -= size[trie[p][ch ^ 1]], p = trie[p][ch];
	}
	return ans;
}

struct Tnode{
	int dat;
	int id, rk;
	bool operator < (const Tnode &rhs) const { return dat < rhs.dat; }
};
priority_queue<Tnode> q;

signed main(){
	n = in; k = in; k <<= 1; int ans = 1;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];
	for(int i = 0; i <= n; i++) build(s[i]);
	for(int i = 0; i <= n; i++) q.push((Tnode){ query(s[i], 1), i, 1 });
	for(int i = 1; i <= k; i++){
		Tnode t = q.top(); ans += t.dat; q.pop();
		if(t.rk < n) q.push((Tnode){ query(s[t.id], t.rk + 1), t.id, t.rk + 1 });
	}
	cout << (ans >> 1) << '\n';
	return 0;
}