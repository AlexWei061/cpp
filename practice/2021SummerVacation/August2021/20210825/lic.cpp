#include<bits/stdc++.h>
using namespace std;

int n = 0;
int arr[10010] = { 0 };

int f[10010] = { 0 };

// f[i] = f[j] + 1 (i < j and a[i] < a[j] and f[i] < f[j] + 1)
void dp(){
    f[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        f[i] = 1;
        for(int j = i + 1; j <= n; j++){
            if(arr[i] < arr[j]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

	dp();

	int ans = 0;
	for(int i = 1; i <= n; i++){
		//printf("%d ", f[i]);
        ans = max(ans, f[i]);
	}
    //puts("");

	printf("%d\n", ans);

	return 0;
}

// 最长不下降子序列