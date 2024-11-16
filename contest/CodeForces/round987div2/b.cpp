#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200
#define INFI 1000000

int t = 0;
int n = 0;
int p[MAXN] = { 0 };

bool chk(){
	bool ans = true;
	for(int i = 1; i <= n; i++){
		if(p[i] == i) continue;
		else if(p[i] == i + 1)
			if(p[i + 1] == i) swap(p[i], p[i + 1]);
			else ans = false;
		else ans = false;
	}
	return ans;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		if(chk()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
