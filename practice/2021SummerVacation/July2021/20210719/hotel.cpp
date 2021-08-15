#include<bits/stdc++.h>
using namespace std;

int hotel[11][11];
int n, k;

void work(){                  //预处理酒店房间号 
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			hotel[i][j] = 100*i + j;
		}
	}
}

int main(){
	freopen("hotel.in", "r", stdin);
	freopen("hotel.out", "w", stdout);
	scanf("%d%d", &n, &k);
	work();
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			ans += hotel[i][j];
			//printf("%d ", hotel[i][j]);
		}
		//puts("");
	}
	printf("%d", ans);
	return 0;
}
