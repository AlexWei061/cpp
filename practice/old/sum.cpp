#include<bits/stdc++.h>
using namespace std;

long long x[1000010] = { 0 };
long long f[1000010] = { 0 };
long long l[1000010] = { 0 };

int main(){
	int t = 0;
	cin >> t;
	for(int a = 0; a < t; a++){
		
    	long long n;
    	cin >> n;
    	for(long long i = 1; i <= n; i++){
			cin >> x[i];
		}
    	f[1] = x[1];
    	for(long long i = 2; i <= n; i++){                                               //最大子段
            f[i] = max(f[i - 1] + x[i], x[i]);
        }
    	for(long long i = 2; i <= n; i++){                                               //同上
            f[i] = max(f[i - 1], f[i]);
        }
    	l[n] = x[n];
    	for(long long i = n - 1; i >= 1; i--){                                           //同上
            l[i] = max(l[i + 1] + x[i], x[i]);
        }
    	for(long long i = n - 1; i >= 1; i--){                                           //同上
            l[i] = max(l[i + 1], l[i]);
        }
    	long long ans=f[1] + f[3];
    	for(long long i=2;i<n;i++){                                                      //中间数
            ans=max(ans,f[i-1]+l[i+1]);
        }
    	cout<<ans;
	}
    return 0;
}
