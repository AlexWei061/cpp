#include<bits/stdc++.h>
using namespace std;

long long n = 0;
long long a[100001] = { 0 };

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%lld", &n);
	int j = 1;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			a[j] = i;
			j++;
		}
	}
	
	for(int i = 1; i < j; i++){
		printf("%d\n", a[i]);
	}
	
	for(int i = j-1; i >= 1; i--){
		printf("%d\n", (int)n/a[i]);
	}
	
	return 0;
}
