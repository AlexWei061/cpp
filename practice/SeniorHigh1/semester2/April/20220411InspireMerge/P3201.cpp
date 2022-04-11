#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 1001000

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int n = 0; int m = 0;
int a[MAXN] = { 0 }; int c[MAXN] = { 0 };
int h[MAXN] = { 0 }; int p[MAXN] = { 0 };
int f[MAXN] = { 0 };

int main(){
    n = in; m = in; int ans = 0;
    for(int i = 1; i <= n; i++){
        a[i] = in; c[a[i]]++; f[a[i]] = a[i];
        p[i] = h[a[i]]; h[a[i]] = i;
        if(a[i] != a[i - 1]) ans++;
    }
    while(m--){
        int op = in;
        if(op == 2) cout << ans << '\n'; 
        else{
            int x = in; int y = in;
            if(x == y) continue;
            if(c[f[x]] > c[f[y]]) swap(f[x], f[y]);
            if(!c[f[x]]) continue;
            x = f[x]; y = f[y];
            for(int i = h[x]; i; i = p[i]){
                if(a[i - 1] == y) ans--;
                if(a[i + 1] == y) ans--;
            } int j = 0;
            for(int i = h[x]; i; i = p[i]) a[j = i] = y;
            p[j] = h[y]; h[y] = h[x]; c[y] += c[x];
            h[x] = c[x] = 0;
        }
    }
    return 0;
}