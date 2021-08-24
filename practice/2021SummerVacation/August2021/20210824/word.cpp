#include<bits/stdc++.h>
using namespace std;

#define P 10007

char str[1000];

int main(){
	int ans = 1;
	scanf("%s", str);
	for(int i = 0; i < strlen(str); i++){
		ans = (ans % P * (str[i] - 'a' + 1) % P) % P;
	}
	printf("%d\n", ans);
	return 0;
}