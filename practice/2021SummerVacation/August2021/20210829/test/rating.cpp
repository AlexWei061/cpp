#include<bits/stdc++.h>
using namespace std;

int n = 0, r = 0;

/*

runtime comlexity : O(1)

*/

int main(){
	freopen("rating.in", "r", stdin);
	freopen("rating.out", "w", stdout);
	scanf("%d%d", &n, &r);
	if(n < 10){
		printf("%d\n", r + 100 * (10 - n)); 
	}
	else{
		printf("%d\n", r);
	}
	return 0;
}
