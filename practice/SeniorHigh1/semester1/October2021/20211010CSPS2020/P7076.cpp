#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n = 0; int m = 0;
int c = 0; int k = 0;

ull a = 0;
bool rule[100] = { 0 };

int main(){
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i = 0; i < n; i++){
		ull temp = 0;
		scanf("%llu", &temp);
		a |= temp;
	}
	//printf("%d\n", a);

	for(int i = 0; i < m; i++){
		int p = 0; int q = 0;
		scanf("%d%d", &p, &q);
		rule[p] = true;
	}

	int cnt = 0;
	for(int i = 0; i < k; i++){
		if(!rule[i] or ((a >> i) & 1)){ 
			cnt++;
		}
	}

	if(cnt == 64 and !n){
		puts("18446744073709551616");
	}
	else{
		ull ans = (cnt == 64) ? ull(-n) : ull((ull(1) << ull(cnt)) - n);
		printf("%llu\n", ans);
	}

	return 0;
}