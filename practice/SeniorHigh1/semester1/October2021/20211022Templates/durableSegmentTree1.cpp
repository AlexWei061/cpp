#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1000100
#define MAXM 1000100

// P3919

int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while(c >= '0' and c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int n = 0; int m = 0;
int a[MAXN] = { 0 };
int root[MAXM] = { 0 };

int cnt = 0;
struct Tnode{
	int ls, rs;
	int val;
}t[32 * MAXN];

int cpy(int node){
	cnt++;
	t[cnt] = t[node];
	return cnt;
}

int build(int node, int l, int r){
	node = ++cnt;
	if(l == r){
		t[node].val = a[l];
		return cnt;
	}
	int mid = (l + r) >> 1;
	t[node].ls = build(t[node].ls, l, mid);
	t[node].rs = build(t[node].rs, mid + 1, r);
	return node;
}

int update(int node, int l, int r, int index, int val){
	node = cpy(node);
	if(l == r){
		t[node].val = val;
	}
	else{
		int mid = (l + r) >> 1;
		if(index <= mid)
			t[node].ls = update(t[node].ls, l, mid, index, val);
		else
			t[node].rs = update(t[node].rs, mid + 1, r, index, val);
	}
	return node;
}

int query(int node, int l, int r, int index){
	if(l == r){
		return t[node].val;
	}
	else{
		int mid = (l + r) >> 1;
		if(index <= mid)
			return query(t[node].ls, l, mid, index);
		else
			return query(t[node].rs, mid + 1, r, index);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d" , &a[i]);
	}
	
	root[0] = build(1, 1, n);
	
	for(int i = 1; i <= m; i++){
		int v = 0, op = 0, loc = 0;
		scanf("%d%d%d", &v, &op, &loc);
		if(op == 1){
			int val = 0;
			scanf("%d", &val);
			root[i] = update(root[v], 1, n, loc, val);
		} 
		else if(op == 2){
			printf("%d\n", query(root[v], 1, n, loc));
			root[i] = root[v];
		}
	}
	
	return 0;
}