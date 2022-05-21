#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int a[MAXN] = { 0 };
int n = 0; int m = 0;

int query(int l, int r){
    int k = r - l + 1; int b[MAXN] = { 0 };
    for(int i = 1; i <= k; i++) b[i] = a[i + l - 1];
    sort(b + 1, b + k + 1); int pos = 1;
    if(b[1] != 1) return 1;
    for(int i = 2; i <= k; i++){
        if(b[i] <= pos + 1) pos += b[i];
        else return pos + 1;
    }
    return pos + 1;
}

int main(){
    n = in;
    for(int i = 1; i <= n; i++) a[i] = in;
    m = in;
    while(m--){
        int l = in; int r = in;
        cout << query(l, r) << '\n';
    }
    return 0;
}