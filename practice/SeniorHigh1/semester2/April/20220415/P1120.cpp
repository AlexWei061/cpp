#include<bits/stdc++.h>
using namespace std;
#define INFI 1 << 30
#define MAXN 100100

int n = 0;
int cnt = 0; int tot = 0;
int mx = 0; int mn = 0;
int t[MAXN] = { 0 };

void dfs(int res, int sum, int target, int p){
    if(res == 0) { printf("%d",target); exit(0); }
    if(sum == target) { dfs(res - 1, 0, target, mx); return; }
    for( int i = p; i >= mn; i --)
        if( t[i] and i + sum <= target){
            t[i]--;
            dfs(res, sum + i, target, i );
            t[i]++;
            if(sum == 0 or sum + i == target) break;
        }
}
int main() {
    scanf("%d", &n); mn = INFI; int temp;
    while(n--) {
        scanf("%d", &temp);
        if(temp <= 50){
            cnt++; t[temp]++; tot += temp;
            mx = mx > temp ? mx : temp;
            mn = mn < temp ? mn : temp;
        }
    }
    temp = tot >> 1;
    for(int i = mx; i <= temp; i++)
        if(tot % i == 0) dfs(tot / i, 0, i, mx);
    printf("%d", tot);
    return 0;
}