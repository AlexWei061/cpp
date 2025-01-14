#include<bits/stdc++.h>
using namespace std;

int T = 0; 

int main(){
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int len = s.size();
		for(int i = len - 1; i >= 0; i--){
			if(s[i] == 'q') cout << 'p';
			if(s[i] == 'p') cout << 'q';
			if(s[i] == 'w') cout << 'w';
		}
		cout << endl;
	}
	return 0;
} 
