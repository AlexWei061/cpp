#include<bits/stdc++.h>
using namespace std;
#define int long long

int l = 0; int r = 0;
int cntl[20] = { 0 }; int cntr[20] = { 0 };
int f[20] = { 0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000, 110000000000, 1200000000000, 13000000000000, 140000000000000, 1500000000000000 };
// 10 µÄ n ´Î·½ 
int power[20] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000 };

/*
void a(){
	int cnt = 0;
	for(int i = 1; i < 10000000; i++){
		int temp = i;
		while(temp){
			int x = temp % 10;
			if(x == 1){
				cnt++;
			}
			temp /= 10;
		}
	} 
	printf("%d\n", cnt);
}
*/

void solve(int x, int cnt[]){
	int num[20] = { 0 }; int len = 0;
	while(x){
		num[++len] = x % 10; x /= 10;
	}
	for(int i = len; i >= 1; i--){
		for(int j = 0; j <= 9; j++){
			cnt[j] += num[i] * f[i-1];
		}
		for(int j = 0; j < num[i]; j++){
			cnt[j] += power[i-1];
		}
		int temp = 0;
		for(int j = i - 1; j >= 1; j--){
			temp = temp * 10 + num[j];
		}
		cnt[num[i]] += temp + 1;
		cnt[0] -= power[i-1];
	}
}

signed main(){
	scanf("%lld%lld", &l, &r);
	solve(l-1, cntl); solve(r, cntr);
	for(int i = 0; i <= 9; i++){
		printf("%lld ", cntr[i] - cntl[i]);
	}
	puts("");
	return 0;
}
