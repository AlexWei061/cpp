#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10010] = { 0 };

int main(){
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        int tans = 1;
        int tidx = i;
        int tval = arr[i];
        while(1){
            if(arr[++tidx] == ++ tval){
                tans++;
            }
            else{
                break;
            }
        }
        ans = max(ans, tans);
    }

    printf("%d\n", ans);

    return 0;
}

