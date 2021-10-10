#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lluu;

int n = 0; int m = 0;
int c = 0; int k = 0;

lluu a = 0;
bool rule[70] = { 0 };

int main(){
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i = 0; i < n; i++){
		lluu temp = 0;
		scanf("%llu", &temp);
		a |= temp;
	}
	//printf("%d\n", a);

	for(int i = 0; i < m; i++){
		int p = 0; int q = 0;
		scanf("%d%d", &p, &q);
		rule[p] = true;
	}

	int num = 0;
	int cnt = 0;
	for(int i = 0; i <= 64; i++){
		if(rule[i]){ 
			cnt++;
			if((a >> i) & 1){
				num++;
			}
		}
	}

	lluu ans = 1 << (k - cnt + num);
	ans -= n;

	printf("%d\n", ans);

	return 0;
}