#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

int n = 0; int m = 0;
char a[MAXN][MAXN];
int  l[MAXN][MAXN] = { 0 };
int  r[MAXN][MAXN] = { 0 };
int  u[MAXN][MAXN] = { 0 };

int main(){
	scanf("%d%d", &n, &m); int ans = 0; int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> a[i][j]; if(a[i][j] == 'F') cnt++;
			l[i][j] = r[i][j] = j; u[i][j] = 1;
		}
	if(cnt == 0) { cout << 0 << '\n'; goto end; }
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++)
			if(a[i][j] == a[i][j - 1] and a[i][j] == 'F')
				l[i][j] = l[i][j - 1];
	for(int i = 1; i <= n; i++)
		for(int j = m - 1; j >= 1; j--)
			if(a[i][j] == a[i][j + 1] and a[i][j] == 'F')
				r[i][j] = r[i][j + 1];
	for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(i > 1)
                if(a[i][j] == a[i - 1][j] and a[i][j] == 'F'){
                    l[i][j] = max(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                    u[i][j] = u[i - 1][j] + 1;
                }
            int a = r[i][j] - l[i][j] + 1;
            int b = min(a, u[i][j]);
            ans = max(a * u[i][j], ans);
        }
    cout << 3 * ans << '\n';
	end : return 0;
}