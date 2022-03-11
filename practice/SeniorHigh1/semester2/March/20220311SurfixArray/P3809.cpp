#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000

int n = 0; int m = 0;
char s[MAXN];
int x[MAXN], y[MAXN], temp[MAXN];
int c[MAXN] = { 0 };
int SA[MAXN] = { 0 };

void Sort(){
	for(int i = 1; i <= m; i++) c[i] = 0;
	for(int i = 1; i <= n; i++) c[x[i]]++;
	for(int i = 2; i <= m; i++) c[i] += c[i - 1];
	for(int i = n; i >= 1; i--) SA[c[x[y[i]]]--] = y[i];
}

void getSA(){
	for(int i = 1; i <= n; i++) x[i] = s[i], y[i] = i; Sort();
	for(int k = 1; k <= n; k <<= 1){
		int cnt = 0;
		for(int i = n - k + 1; i <= n; i++) y[++cnt] = i;
		for(int i = 1; i <= n; i++) if(SA[i] > k) y[++cnt] = SA[i] - k;
		Sort(); swap(x, temp); x[SA[1]] = 1; int num = 1;
		for(int i = 2; i <= n; i++){
			if(temp[SA[i]] == temp[SA[i - 1]] and temp[SA[i] + k] == temp[SA[i - 1] + k])
				x[SA[i]] = num;
			else x[SA[i]] = ++num;
		} m = num;
	}
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1); m = 127;
	getSA();
	for(int i = 1; i <= n; i++) cout << SA[i] << ' ';
	puts("");
	return 0;
}