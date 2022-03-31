#include <bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 500500

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int k[MAXN] = { 0 };
int id[MAXN] = { 0 };
int lst[MAXN] = { 0 };
vector <int> g[MAXN];
int T = 0; int n = 0;
bool comp(int x, int y) { return k[x] > k[y]; }

int main(){
	T = in;
	while(T--){
		n = in; memset(lst, 0, sizeof(lst));
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i <= n; i++){
			k[i] = in; id[i] = i;
			for(int j = 1; j <= k[i]; j++) g[i].push_back(in);
		}
		sort(id + 1, id + n + 1, comp);
		int now = 0; int x = 0; int y = 0;
		for(int i = 1; i <= n; i++){
			now = id[i]; x = y = 0;
			for(int j : g[now]){
				int p = lst[j]; lst[j] = now;               // 维护 last[i] 
				if(!p) p = now;                             // lst[p] 为空 
				if(!x) x = p;                               // 之前的题中没有给 x 赋值 
				else if(x ^ p) y = p;                       // 找到另一道题 y 
				if(x and y) goto yes;
			}
		}
		puts("NO"); continue;
		yes :
		if(x ^ now and y ^ now)
			if(k[x] > k[y]) x = now;
			else y = now;
		cout << "YES" << '\n' << x << ' ' << y << '\n';
	}
	return 0;
}
