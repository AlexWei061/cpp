#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n = 0;
int a[MAXN] = { 0 };                                     // Îä´ó 
int b[MAXN] = { 0 };                                     // »ª¿Æ 
int k = 0;

void solve(){
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	cin >> k;
	solve();
	return 0;
} 
