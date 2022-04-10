#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1010

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int n = 0; int m = 0;
int a[MAXN][MAXN] = { 0 };
int c[MAXN][MAXN] = { 0 };

int main(){
    n = in; m = in;
    for(int i = 1; i <= m; i++){
        int xs = in; int ys = in;
        int xe = in; int ye = in; 
        for(int j = xs; j <= xe; j++)
            c[j][ys]++, c[j][ye + 1]--;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = a[i][j - 1] + c[i][j];
            cout << a[i][j] << ' ';
        }
        puts("");
    }
    return 0;
}