#include<bits/stdc++.h>
using namespace std;
#define int long long

int T = 0;
int x = 0, m = 0; 

signed main(){
	cin >> T;
	while(T--){
		cin >> x >> m;
		int cnt = 0;
		for(int i = 1; i <= min(m, 2 * x); i++)
			if((i ^ x) == 0) continue;
			else if(((x % (x ^ i)) == 0) or ((i % (x ^ i)) == 0)) cnt++; 
		cout << cnt << endl;
	}
//	for(int i = 1; i <= 100; i++){
//		cout << "x = " << i << endl;
//		for(int j = 1; j <= 1000; j++)
//			if((i ^ j) == 0) continue;
//			else if(((i % (i ^ j)) == 0) or ((j % (i ^ j)) == 0)) cout << j << ' ';
//		cout << endl << endl;
//	}
	return 0;
}
