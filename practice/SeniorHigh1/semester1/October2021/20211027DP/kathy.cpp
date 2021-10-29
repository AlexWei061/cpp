#include<bits/stdc++.h>
using namespace std;

int kathy(int x){
	if(x == 1 or x == 3) return x;
	if(x % 2 == 0) return kathy(x / 2);
	if(x % 4 == 1){
		int n = x / 4;
		return 2 * kathy(2 * n + 1) - kathy(n);
	}
	if(x % 4 == 3){
		int n = x / 4;
		return 3 * kathy(2 * n + 1) - 2 * kathy(n);
	}
}

int main(){
	for(int i = 1; i <= 1000; i++){
		if(i == kathy(i)) printf("%d ", i);
	}
	return 0;
}
