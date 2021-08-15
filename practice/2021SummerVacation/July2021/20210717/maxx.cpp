#include<bits/stdc++.h>
using namespace std;

#define INFI 65535

int n              =   0  ;
int numlist[10001] = { 0 };

int findMax(int n, int numlist[]){
	int maxx = -INFI;
	for(int i = 0; i < n; i++){
		maxx = max(maxx, numlist[i]);
	}
	return maxx;
}

int main(){
	freopen("maxx.in", "r", stdin);
	freopen("maxx.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &numlist[i]);
	}
	printf("%d", findMax(n, numlist));
	return 0;
}
