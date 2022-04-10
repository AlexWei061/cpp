#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n = 0;
int a[MAXN][MAXN] = { 0 };
int s[MAXN][MAXN] = { 0 };

int main(){
    scanf("%d", &n); int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]); s[i][j] = a[i][j];
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= n; j++)
            for(int x = i + 1; x <= n; x++) 
                for(int y = j + 1; y <= n; y++)
                    ans = max(ans, s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1]);
    cout << ans << '\n';
    return 0;
}