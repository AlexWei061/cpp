#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int x = 0;
int n = 0;
int a[MAXN] = { 0 };

int h = 0, t = 0;
int nx[MAXN] = { 0 };

int main(){
	cin >> x;
	while(x--){
		cin >> n;
		h = 2, t = 1;
		nx[2] = 4, nx[4] = 5, nx[5] = 3, nx[3] = 1;
		if(n <= 4) cout << -1 << endl;
		else{
			for(int i = 6; i <= n; i++)
				if(i % 2 == 0) nx[i] = h, h = i;
				else nx[t] = i, t = i;
			for(int p = h; p; p = nx[p]) cout << p << ' ';
			cout << endl;
		}
	}
	return 0;
}
