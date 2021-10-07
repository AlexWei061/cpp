#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define P 998244353

//int ans = 0;
int n = 0;
int x[MAXN] = { 0 };
int d[MAXN] = { 0 };

int f[MAXN][MAXN] = { 0 };
void go(int x){

}

bool way[MAXN];
int dfs(int x, bool isAct){
	if(x == n + 1){

	}
	else{
		if(!way[x]){
			way[x] = 1;
			if(isAct){
				go(x);
			}
			dfs(x + 1, 1);
			dfs(x + 1, 0);	
		}
	}
}

int main(){
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
    /*
	srand(time(0));
	ans = rand() % P + 1;
	printf("%d\n", ans);
	*/

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &x[i], &d[i]);
	}

	dfs(1, 0);
    dfs(1, 1);

    return 0;
}