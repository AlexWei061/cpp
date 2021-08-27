#include<bits/stdc++.h>
using namespace std;

#define MAXN 101
#define INFI 0x3f3f3f3f

int n, m;
int f[MAXN][MAXN] = { 0 };

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][k]+f[k][j], f[i][j]);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= m; i++){
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		f[x][y] = 1;
	}

	floyd();

    /*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%-11d ", f[i][j]);
		}
		puts("");
	}
    */

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int temp =0;
        for(int j = 1; j <= n; j++){
            if(f[i][j] < INFI or f[j][i] < INFI){
                temp++;
            }
        }
        if(temp == n - 1){
            ans++;
        }
    }
    printf("%d\n", ans);

	return 0;
}


/*

N (1 ≤ N ≤ 100) cows, conveniently numbered 1..N, are participating in a programming contest. 
As we all know, some cows code better than others. Each cow has a certain constant skill rating 
that is unique among the competitors.

The contest is conducted in several head-to-head rounds, each between two cows. 
If cow A has a greater skill level than cow B (1 ≤ A ≤ N; 1 ≤ B ≤ N; A ≠ B), then cow A will 
always beat cow B.

Farmer John is trying to rank the cows by skill level. Given a list the results of 
M (1 ≤ M ≤ 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely 
determined from the results. It is guaranteed that the results of the rounds will not be 
contradictory.

5 5
4 3
4 2
3 2
1 2
2 5

2

*/