#include<bits/stdc++.h>
using namespace std;

#define INFI 1 << 30
#define MAXN 100100
#define MAXK 505

int One = 0;
int n = 0; int k = 0;

int t[MAXN] = { 0 };
int x[MAXK] = { 0 };
int c[MAXK] = { 0 };
int sum[MAXN] = { 0 };

int f[MAXN][MAXK] = { 0 };                  // f[i][j] --> 对于 t[i], x[i] 能最早追溯到的时间的下标 
void work(int t[], int x[]){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			f[i][j] = upper_bound(t + 1, t + n + 1, t[i] - x[j]) - t;
		}
	}
}

/* sum[i]  第 i 此时的最小花费  sum[i] = min{ min{sum[i-1] + One, sum[f[i][j]-1] + c[j} } 其中 1 <= j <= k */
void dp(){
	for(int i = 1; i <= n; i++){
		int ans = INFI;
		//printf("i = %d\n", i);
		for(int j = 1; j <= k; j++){
			//printf("	j = %d sum[i-1] + One = %d sum[f[i][j] - 1] + c[j] = %d\n", j, sum[i - 1] + One, sum[f[i][j] - 1] + c[j]);
			ans = min(ans, min(sum[i - 1] + One, sum[f[i][j] - 1] + c[j]));
			//printf("	ans = %d\n\n", ans);
		}
		sum[i] = ans;
	}
}

int main(){
	freopen("buy.in", "r", stdin);
	freopen("buy.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	
	if(k == 0){
		for(int i = 1; i <= n; i++){
			int temp = 0;
			scanf("%d", &temp);
		}
		scanf("%d", &One);
		for(int i = 1; i <= n; i++){
			printf("%d\n", One);
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			scanf("%d", &t[i]);
		}
		for(int i = 1; i <= k; i++){
			scanf("%d%d", &x[i], &c[i]);
		}
		scanf("%d", &One);
		
		/*
		for(int i = 1; i <= n; i++){
			printf("t[%d] = %d\n", i, t[i]);
		}
		puts("");
		for(int i = 1; i <= k; i++){
			printf("x[%d] = %d c[%d] = %d\n", i, x[i], i, c[i]);
		}
		puts("");
		printf("One = %d\n\n", One);
		*/
		
		work(t, x);
		
		/*
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= k; j++){
				printf("f[%d][%d] = %d  ", i, j, f[i][j]);
			}
			puts("");
		}
		puts("");
		*/
		
		dp();
		
		for(int i = 1; i <= n; i++){
			printf("%d\n", sum[i] - sum[i-1]);
		}
	}
	
	return 0;
}