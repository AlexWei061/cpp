#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n = 0;
double PF[MAXN] = { 0 }; 
double PAF[MAXN] = { 0 };

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> PF[i];
	for(int i = 1; i <= n; i++) cin >> PAF[i];
	double ans = 0;
	for(int i = 1; i <= n; i++) ans += PF[i] * PAF[i];
	cout << ans << '\n';
	return 0;
} 
