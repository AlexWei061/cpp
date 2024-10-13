#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200

int T = 0;

int main(){
	cin >> T;
	while(T--){
		string num; char op;
		cin >> num >> op;
		int len = num.size();
//		for(int i = 0; i < len; i++) cout << num[i]; puts("");
		if(len == 1) cout << -1 << '\n';
		else if(len == 2){
			int a = num[0] - '0', b = num[1] - '0';
			if(op == '>' and a > b) cout << a << '>' << b << '\n';
			else if(op == '<' and a < b) cout << a << '<' << b << '\n';
			else cout << -1 << '\n';
		}
		else{
			if(op == '>'){
				for(int i = 0; i < len - 1; i++) cout << num[i];
				cout << '>' << num[len - 1] << '\n';
			}
			else{
				if(num[1] != '0'){
					cout << num[0] << '<';
					for(int i = 1; i < len; i++) cout << num[i]; puts("");	
				}
				else{
					int cnt = 0;
					for(int i = 1; i < len; i++)
						if(num[i] == '0') cnt++;
						else break;
					if(cnt == len - 1) cout << -1 <<  '\n';
					else if(cnt == len - 2){
						int a = num[0] - '0', b = num[len - 1] - '0';
						if(a < b){
							cout << num[0] << '<';
							for(int i = 1; i < len; i++) cout << num[i]; puts("");
						}
						else cout << -1 << '\n';
					}
					else{
						cout << num[0] << '<';
						for(int i = 1; i < len; i++) cout << num[i]; puts("");
					}
				}
			}
		}
	}
	return 0;
} 
