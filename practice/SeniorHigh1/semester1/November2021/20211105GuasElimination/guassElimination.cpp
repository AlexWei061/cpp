#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-7

int n = 0;
double mmap[111][111] = { 0 };
double ans[111] = { 0 };

void solve(){
	for(int i = 1; i <= n; i++){ 
        int r = i;
        for(int j = i + 1; j <= n; j++)                        // 找到这一列的最大值
            if(fabs(mmap[r][i]) < fabs(mmap[j][i]))
                r = j;
        if(fabs(mmap[r][i]) < EPS){                            // 如果某一列全是 0 就无解 
            printf("No Solution"); return;
        }
        if(i != r) swap(mmap[i], mmap[r]);                     // 交换这两行 方便在本行进行消元 
        double div = mmap[i][i];
        for(int j = i; j <= n + 1; j++)                        // 系数置为 1
            mmap[i][j] /= div;
        for(int j = i + 1; j <= n; j++){                       // 消元 
            div = mmap[j][i];
            for(int k = i; k <= n + 1; k++)
                mmap[j][k] -= mmap[i][k] * div;
        }
    }
    ans[n] = mmap[n][n + 1];
    for(int i = n - 1; i >= 1; i--){                           // 回带
        ans[i] = mmap[i][n + 1];
        for(int j = i + 1; j <= n; j++)
            ans[i] -= (mmap[i][j] * ans[j]);
    }
    for(int i = 1; i <= n; i++) printf("%.2lf\n", ans[i]);
} 

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n + 1; j++)
            scanf("%lf", &mmap[i][j]);
    solve();
}