#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 200200
#define INFI 0x7f7f7f7f7f7f7f7f

inline int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <= '9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int ans = 0;
int n = 0; int m = 0; int s = 0;
int v[MAXN] = { 0 }; int w[MAXN] = { 0 };
int l[MAXN] = { 0 }; int r[MAXN] = { 0 };

int sv[MAXN] = { 0 }; int sw[MAXN] = { 0 };
bool check(int W){
    int y = 0;
    for(int i = 1; i <= n; i++)
        if(w[i] >= W) sw[i] = sw[i - 1] + 1, sv[i] = sv[i - 1] + v[i];
        else sw[i] = sw[i - 1], sv[i] = sv[i - 1];
    for(int i = 1; i <= m; i++)
        y += (sw[r[i]] - sw[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]);
    ans = llabs(y - s);
    if(y > s) return true;
    else return false;
}

signed main(){
    n = in; m = in; s = in; int mx = 0; int mm = INFI;
    for(int i = 1; i <= n; i++){
        w[i] = in; v[i] = in;
        mx = max(mx, w[i]); mm = min(mm, w[i]);
    }
    for(int i = 1; i <= m; i++) l[i] = in, r[i] = in;
    int L = mm - 1; int R = mx + 1; int res = INFI;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(check(mid)) L = mid + 1;
        else R = mid - 1;
        res = min(res, ans);
    }
    cout << res << '\n';
    return 0;
}