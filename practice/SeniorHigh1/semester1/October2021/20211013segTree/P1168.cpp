#include<bits/stdc++.h>
using namespace std;

int n = 0;
vector<int> a;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int temp = 0;
		scanf("%d", &temp);
		a.insert(upper_bound(a.begin(), a.end(), temp), temp);
		if(i % 2 == 1){
			printf("%d\n", a[(i - 1) / 2]);
		}
	}
	return 0;
}
