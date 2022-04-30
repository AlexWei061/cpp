#include<bits/stdc++.h>
using namespace std;

int qp(int a, int b, int p){
	int ans = 1 % p;
	for(; b; b >>= 1){
		if(b & 1) ans = (long long) ans * a % p;
		a = (long long) a * a % p;
	}
	return ans;
}

int main(){
	int a = 0; int b = 0; int p = 0;
	scanf("%d%d%d", &a, &b, &p);
	cout << qp(a, b, p) << '\n';
	return 0;
}