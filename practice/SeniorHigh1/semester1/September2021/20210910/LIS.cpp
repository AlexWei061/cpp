#include<bits/stdc++.h>
using namespace std;

#define N 10

/*

Dinamic Transfer equation:

dp[i] = max{1, dp[j] + 1}   ( 1 <= j < i )

*/

int ans = -1;
int arr[N] = { 0, 1, 2, 3, -1, -2, 7, 9 };
int   f[N] = { 0 };

void dp(){
	for(int i = 1; i <= N; i++){
		f[i] = 1;
        for(int j = 1; j < i; j++){
			if((arr[i] >= arr[j]) and (f[j] + 1 > f[i])){
                f[i] = f[j] + 1;
            }
		}
        ans = max(ans, f[i]);
	}
}

int main(){
	dp();
	
    printf("arr[] : ");
    for(int i = 1; i <= N; i++){
        printf("%-2d ", arr[i]);
    }
    puts("");

    printf("f[]   : ");
	for(int i = 1; i <= N; i++){
		printf("%-2d ", f[i]);
	}
	puts("");

    printf("ans = %d\n", ans);

    return 0;
}