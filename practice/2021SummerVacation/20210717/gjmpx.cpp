#include<bits/stdc++.h>
using namespace std;

int n = 0;
string name[100001];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> name[i];
	}
	sort(name, name+n);
	
	for(int i = 0; i < n; i++){
		cout << name[i] << endl;
	}
	
	return 0;
}
