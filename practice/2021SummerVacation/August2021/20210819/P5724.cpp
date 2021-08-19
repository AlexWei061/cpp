#include<bits/stdc++.h>
using namespace std;

int n = 0;
int arr[10001] = { 0 };

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr + 1, arr + n + 1);

    printf("%d\n", arr[n] - arr[1]);

    return 0;
}