#include<bits/stdc++.h>
using namespace std;

long long a, b, c, d, x;

int main(){
	freopen("buy.in", "r", stdin);
	freopen("buy.out", "w", stdout);
	cin >> a >> b >> c >> d >> x;
	long long tot = a * b + c * d;
	x >= tot ? cout << "YES" << endl : cout << "NO" << endl;
	cout << abs(x - tot) << endl;
	return 0;
}
