#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int T = 0;
int n = 0, k = 0;
int idx = 0;
int a[MAXN] = { 0 };

bool chk(){
	for(int i = 1; i <= n; i++){
		bool flag = true;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(abs(a[i] - a[j]) % k == 0) { flag = false; break; }
		}
		if(flag) { idx = i; return true; }
	}
	return false;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(chk()) cout << "YES" << endl << idx << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 
