#include<bits/stdc++.h>
using namespace std;

int num = 0;

int  reverse(int num){
	int ans = 0;
	while(num != 0){
		ans = (ans * 10) + (num % 10);
		num /= 10;
	}
	return ans;
}

int main(){
	scanf("%d", &num);
	int ans = reverse(num);
	printf("%d", ans);
	return 0;
}
