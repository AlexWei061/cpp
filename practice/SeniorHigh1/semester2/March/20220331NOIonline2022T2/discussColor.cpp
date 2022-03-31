#include<bits/stdc++.h>
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

int T = 0; int n = 0;
vector<int> g[MAXN];
struct Tpeo{
	int k; int idx;
	bool operator < (const Tpeo &rhs) const {
		return k > rhs.k; 
	}
}peo[MAXN];

int col = 0;
int v[MAXN] = { 0 };                          // 染色盘 

int main(){
	T = in;
	while(T--){
		n = in; memset(v, 0, sizeof(v)); col = 0;
		for(int i = 1; i <= n; i++){
			peo[i].k = in; peo[i].idx = i; g[i].clear();
			for(int j = 1; j <= peo[i].k; j++) g[i].push_back(in);
		}
		sort(peo + 1, peo + n + 1); bool same = true;
		for(int i = 1; i <= n; i++){
			int now = peo[i].idx; col++; int c = v[g[now].front()];
			if(!peo[i].k) continue;
			for(int j : g[now]){
				if(v[j] != c) { if(!c) c = v[j]; same = false; break; }
				v[j] = col;
			}
			if(!same) { cout << "YES" << '\n' << now << ' ' << peo[c].idx << '\n'; break; }
		}
		if(same) cout << "NO" << '\n';
	}
	return 0;
}