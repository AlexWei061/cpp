#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int l = 0, r = 0;

bool ch(int n){
	if((n - 2022) % 4 == 0) return 1;
	else if((n - 2024) % 4 == 0) return 1;
	else return 0;
}

int main(){
	cin >> l >> r;
	for(int i = l; i <= r; i++) if(ch(i)) ans++;
	cout << ans << '\n';
	return 0;
} 
