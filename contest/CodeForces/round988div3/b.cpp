#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int t = 0;
int k = 0;
int a[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	cin >> t;
	while(t--){
		cin >> k;
		for(int i = 1; i <= k; i++) cin >> a[i];
		for(int i = 1; i <= k; i++) c[a[i]]++;
		k -= 2;
		for(int i = 1; i * i <= k; i++)
			if(k % i == 0 and c[i] and c[k / i]){
				cout << i << ' ' << k / i << endl; break;
			}
		k += 2;
		for(int i = 1; i <= k; i++) a[i] = c[i] = 0;
	}
	return 0;
} 
