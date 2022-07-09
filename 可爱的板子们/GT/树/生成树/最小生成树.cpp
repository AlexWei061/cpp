#includebitsstdc++.h
using namespace std;
#define MAXN 5050
#define MAXM 200200

int n = 0; int m = 0;

struct Tedge{
	int x, y;
	int val;
}edge[MAXM];
bool comp(Tedge a, Tedge b){
	return a.val  b.val;
}

int parent[MAXN] = { 0 };

void init(){
	for(int i = 1; i = n; i++){
		parent[i] = i;
	}
}

int findRoot(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = findRoot(parent[x]);
}

void merge(int x, int y){
	parent[findRoot(x)] = findRoot(y);
}

int ans = 0;
void kruskal(){
	sort(edge+1, edge+m+1, comp);
	for(int i = 1; i = m; i++){
		Tedge e = edge[i];
		if(findRoot(e.x) != findRoot(e.y)){
			merge(e.x, e.y);
			ans += e.val;
		}
	}
}

int main(){
	scanf(%d%d, &n, &m);
	init();
	for(int i = 1; i = m; i++){
		scanf(%d%d%d, &edge[i].x, &edge[i].y, &edge[i].val);
		merge(edge[i].x, edge[i].y);
	}
	
	int cnt = 0;
	for(int i = 1; i = n; i++){
		if(parent[i] == i) cnt++;
	}
	if(cnt  1){
		printf(orzn);
	}
	else{
		init();
		kruskal();
		printf(%dn, ans);
	}
	return 0;
}
