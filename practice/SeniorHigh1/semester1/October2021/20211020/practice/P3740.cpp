#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001000

int ans = 0;
bool flag = false;
int n = 0; int m = 0;
bool colored[4 * MAXN] = { 0 };
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };

int ls(int p){
	return p << 1;
}
int rs(int p){
	return p << 1 | 1;
}

void update(int p, int nodeL, int nodeR, int l, int r){
	if(colored[p]) return;
	if(l <= nodeL and nodeR <= r){
		flag = 1; colored[p] = 1;
		return;
	}
	int mid = (nodeL + nodeR) >> 1;
	if(l <= mid) update(ls(p), nodeL, mid, l, r);
	if(r > mid)  update(rs(p), mid + 1, nodeR, l, r);
	colored[p] = (colored[ls(p)] and colored[rs(p)]);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	for(int i = m; i >= 1; i--){
		flag = false;
		update(1, 1, n, a[i], b[i]);
		if(flag) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
