#include<bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n = 0, k = 0;
int p[MAXN] = { 0 };

/*

runtime complexity : O(nlogn)

*/

int main(){
	freopen("fruit.in", "r", stdin);
	freopen("fruit.out", "w", stdout);
	scanf("%d%d", &n, &k);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	
	sort(p, p+n);
	
	int ans = 0;
	for(int i = 0; i < k; i++){
		ans += p[i];
	}
	
	printf("%d\n", ans);	
	return 0;
}
