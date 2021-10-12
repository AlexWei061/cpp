#include<bits/stdc++.h>
using namespace std;

const int P = (int) 1e9 + 7;

int n = 0;
int ans = 1;

int main(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	vector<int> b(1, 1);
	for(int i = 1; i < n; i++){
		if(a[i] != b.back() + 1){
			b.push_back(b.back() + 2);
		}
		else{
			ans = ((long long) ans % P * (b.size() + 1) % P) % P;
		}
	}
	
	for(int i = 0; i < (int) b.size(); i++){
		ans = ((long long) ans % P * (i + 1) % P) % P;
	}
	printf("%d\n", ans);
	
	return 0;
}
