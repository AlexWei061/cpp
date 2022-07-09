#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define MAXM 2020
typedef unsigned long long ull;
#define P 13331

int n = 0;
char str[MAXM];
ull a[MAXN] = { 0 };

ull Hash(char str[]){
	ull ans = 0;
	ull len = strlen(str);
	for(int i = 0; i < len; i++){
		ans += ans * P + (ull)str[i];
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", str);
		a[i] = Hash(str);
	}
	sort(a+1, a+n+1);
	ull cnt =0;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i+1]) cnt++;
	}
	printf("%llu\n", cnt);
	return 0;
}
