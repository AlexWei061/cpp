#include<bits/stdc++.h>
using namespace std;

int t = 0;
int a = 0, b = 0, n = 0;
string pat;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		cin >> pat;
		int x = 0, y = 0, round = 100000;
		bool can = false;
		while(round--){
			for(int i = 0; i < n; i++){
				if(pat[i] == 'N') y++;
				if(pat[i] == 'S') y--;
				if(pat[i] == 'E') x++;
				if(pat[i] == 'W') x--;
				if(x == a and y == b) { can = true; goto endLoop; }
			}
		}
		endLoop:
			if(can) cout << "YES\n";
			else cout << "NO\n"; 
	}
	return 0;
} 
