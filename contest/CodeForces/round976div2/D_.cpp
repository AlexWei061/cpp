#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int t = 0;
int n = 0, m = 0;

int aa[MAXN] = { 0 };
int fa[MAXN] = { 0 };
inline void init() { for(int i = 1; i <= n; i++) fa[i] = i, aa[i] = 0; }
inline int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void add(int x, int y) { fa[find(x)] = find(y); }

void update(int a, int d, int k){
	for(int i = 1; i <= k; i++) add(a + (i - 1) * d, a + i * d);
}

int query(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x = find(i);
		if(!aa[x]) ans++, aa[x]++;
	}
	return ans;
}

int main(){
	t = in;
	while(t--){
		n = in, m = in;
		init();
		while(m--){
			int a = 0, d = 0, k = 0;
			a = in, d = in, k = in;
			update(a, d, k);
		}
		cout << query() << '\n';
	}
	return 0;
} 
