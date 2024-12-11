#include<bits/stdc++.h>
using namespace std;

int T = 0;
int a = 0, b = 0;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(){
	cin >> T;
	while(T--){
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}
