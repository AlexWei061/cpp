#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int T = 0;
int n = 0;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++) cout << 2 * i - 1 << ' ';
		cout << endl; 
	}
	return 0;
} 
