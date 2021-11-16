#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1100000;
const ll Inf_ll = 0x3f3f3f3f3f3f3f;
vector<int>g[Maxn], q[Maxn];
int deg[Maxn];
int v[Maxn], e[Maxn], d[Maxn], fa[Maxn];
bool nice[Maxn];
int n, m;
int N, M, B;

int find_fa(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find_fa(fa[x]);
}

void merge(int x, int y) {
	int fa_x = find_fa(x), fa_y = find_fa(y);
	e[fa_x]++;
	if (fa_x == fa_y)
		return ;
	fa[fa_y] = fa_x;
	v[fa_x] += v[fa_y];
	e[fa_x] += e[fa_y];
	d[fa_x] += d[fa_y];
}

ll calc(int x) {
	x = find_fa(x);
	return 1ll * M * e[x] - 1ll * N * v[x] + 1ll * B * (d[x] - (e[x] << 1));
}

int main() {
	freopen("subgraph.in","r",stdin) ;
	freopen("subgraph.out","w",stdout) ;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &M, &N, &B);
	ll ans = -Inf_ll;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 0; i < n; i++) {
		fa[i] = i;
		d[i] = deg[i];
		v[i] = 1;
		q[d[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int len = 0;
		for (int j = 0; j < q[i].size(); j++) {
			int u = q[i][j];
			if (deg[u] == -1)
				continue;
			q[i][len++] = u;
			deg[u] = -1;
			for (int k = 0; k < g[u].size(); k++) {
				int v = g[u][k];
				if (deg[v] != -1) {
					deg[v]--;
					q[max(i, deg[v])].push_back(v);
				}
			}
		}
		q[i].resize(len);
	}
	int res = 0;
	for (int i = n - 1; i > 0; i--) {
		for (auto u : q[i]) {
			nice[u] = 1;
			for (auto v : g[u])
				if (nice[v])
					merge(u, v);
		}
		for (auto u : q[i]) {
			ll v = calc(u);
			if (v > ans) {
				ans = v;
				res = i;
			}
		}
	}
	printf("%d %lld\n", res, ans);
}
