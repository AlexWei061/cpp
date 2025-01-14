#include<bits/stdc++.h>
using namespace std;
#define MAXN 300300

int T = 0;
int n, m, k;
int a[MAXN] = { 0 };
int q[MAXN] = { 0 };

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		for(int i = 1; i <= m; i++) cin >> a[i];
		for(int i = 1; i <= k; i++) cin >> q[i];
		if(k < n - 1){
			for(int i = 1; i <= m; i++) cout << 0;
			cout << endl;
		}
		else if(k == n - 1){
			int v[MAXN], unable = -1;
			for(int i = 1; i <= n; i++) v[i] = 0;
			for(int i = 1; i <= k; i++) v[q[i]] = 1;
			for(int i = 1; i <= n; i++) if(!v[i]) unable = i;
			for(int i = 1; i <= m; i++)
				if(a[i] == unable) cout << 1;
				else cout << 0;
			cout << endl; 
		}
		else{
			for(int i = 1; i <= m; i++) cout << 1;
			cout << endl;
		}
		
	}
	return 0;
} 
