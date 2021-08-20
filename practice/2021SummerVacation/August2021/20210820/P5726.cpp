#include<bits/stdc++.h>
using namespace std;

int n = 0;
int arr[10010] = { 0 };

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    int tot = 0;
    for(int i = 1; i < n-1; i++){
        tot += arr[i];
    }

    double ans = tot * 1.0 / (n-2);

    printf("%.2lf\n", ans);

    return 0;
}