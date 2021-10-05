#include<bits/stdc++.h>
using namespace std;

const int e=100020;
int f[e] = { 0 }, g[e] = { 0 }, a[e] = { 0 }, link[e] = { 0 }; //f[i]表示 i 这个根要，g[i]表示 i 这个根不要
int n, t = 0;

struct qq{
 int y, next;
}ee[2*e];

void insert(int startt, int endd){
    ee[++t].y = endd; 
    ee[t].next = link[startt];
    link[startt] = t;
}

void dfs(int root, int father){
    int tempf = 0, tempg = 0;
    for(int i = link[root]; i; i = ee[i].next){
        if(ee[i].y != father){
            dfs(ee[i].y,root);
            f[root] += g[ee[i].y];
            g[root] += max(f[ee[i].y], g[ee[i].y]);
        }
    }
    f[root]+=a[root];
}

int main(){
    //freopen("profit.in","r",stdin);
    //freopen("profit.out","w",stdout);
    cin >> n;
 for(int i = 1; i <=n ; i++)
    scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        insert(xx, yy);
        insert(yy, xx);
    }
    dfs(1, 1);
    cout << max(f[1], g[1]);
    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int v[MAXN] = { 0 };

int first[MAXN] = { 0 };
int   nxt[MAXN] = { 0 };
int    to[MAXN] = { 0 };
//int value[MAXN] = { 0 };
int tot = 0;

void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	//value[tot] = weight;
}

int f[MAXN][10] = { 0 };
void dp(int x, int fx){
	int temp0 = 0; int temp1 = 0;
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(y != fx){
			dp(y, x);
			f[x][0] += max(f[y][0], f[y][1]);
			f[x][1] += f[y][0];
		}
	}
	f[x][1] += v[x];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	for(int i = 1; i < n; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}

	dp(1, 1);

	printf("%d\n", max(f[1][0], f[1][1]));

	return 0;
}
*/