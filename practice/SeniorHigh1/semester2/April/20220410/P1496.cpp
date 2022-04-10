#include<bits/stdc++.h>
using namespace std;
#define MAXN 20200

int n = 0;
long long a[MAXN] = { 0 };
long long b[MAXN] = { 0 };
int ans = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        ans += b[i] - a[i];
        if(i < n)
            if(b[i] > a[i + 1])
                ans -= b[i] - a[i + 1];
    }
    cout << ans;
    return 0;
}