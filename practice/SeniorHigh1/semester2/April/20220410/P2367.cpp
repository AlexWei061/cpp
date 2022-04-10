#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 5005000
#define INFI 1 << 30

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int a[MAXN] = { 0 };
int c[MAXN] = { 0 };
int n = 0; int p = 0;

int main(){
    n = in; p = in; int ans = INFI;
    for(int i = 1; i <= n; i++) a[i] = in, c[i] = a[i] - a[i - 1];
    for(int i = 1; i <= p; i++){
        int l = in; int r = in; int x = in;
        c[l] += x; c[r + 1] -= x;
    }
    for(int i = 1; i <= n; i++) { a[i] = a[i - 1] + c[i]; ans = min(ans, a[i]); }
    cout << ans << '\n';
    return 0;
}