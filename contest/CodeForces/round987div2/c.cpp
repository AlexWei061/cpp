#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200
#define INFI 1000000

int t = 0;
int n = 0;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		if(n % 2 == 0){
			for(int i = 1; i <= n / 2; i++) cout << i << ' ' << i << ' ';
			puts("");
		}
		else
			if(n <= 25) cout << -1 << '\n';
			else{
				cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
				for(int i = 28; i <= n; i++)
					cout << (int)ceil(((double)i - 27.0) / 2.0) + 13 << ' ';
				cout << endl;
			}
	}
	return 0;
}
