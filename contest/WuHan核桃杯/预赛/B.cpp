#include<bits/stdc++.h>
using namespace std;

int T = 0;
int n = 0;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		n %= 3;
		if(n % 3 == 0) cout << "A\n";
		if(n % 3 == 1) cout << "B\n";
		if(n % 3 == 2) cout << "C\n";
	}
	return 0;
}
