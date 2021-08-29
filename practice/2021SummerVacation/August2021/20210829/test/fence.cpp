#include<bits/stdc++.h>
using namespace std;

#define MAXN 20200

int n = 0;
int tot = 0;
int len[MAXN] = { 0 };

bool comp(int a, int b){
	return a > b;
}

/*

runtime complexity : O(nlogn)

*/

int main(){
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &len[i]);
		tot += len[i];
	}
	sort(len, len+n, comp);
	
	unsigned long long ans = 0;
	for(int i = 0; i < n-1; i++){
		ans += tot;
		tot -= len[i];
	}
	
	printf("%llu\n", ans);
	
	return 0;
}
