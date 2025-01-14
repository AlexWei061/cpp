#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int T = 0;
int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i <= n; i++) a[i] = b[i] = c[i] = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		int cnt = 1;
		for(int i = 1; i <= n; i++){
//			cout << "i = " << i << endl;
//			cout << "cnt = " << cnt << endl;
//			cout << "c : "; for(int i = 0; i <= n; i++) cout << c[i] << ' '; puts("");
//			cout << "b : "; for(int i = 0; i <= n; i++) cout << b[i] << ' '; puts("");
			if(!c[a[i]]) b[i] = a[i];
			else{
				while(c[cnt]){
//					cout << "  " << cnt << endl;
//					cout << "  " << a[cnt] << endl;
//					cout << "  " << c[a[cnt]] << endl;
					cnt++;
				}
				b[i] = cnt;
			}
			c[b[i]] = 1;
		}
		for(int i = 1; i <= n; i++) cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}
