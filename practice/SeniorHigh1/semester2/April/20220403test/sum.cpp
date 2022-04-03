#include<bits/stdc++.h>
using namespace std;
#define MAXN 5050
#define N 1000

int d[MAXN] = { 0 };
int p[MAXN] = { 0 };
int s = 0;
int f[MAXN] = { 0 };

void prework(){
	for(int i = 1; i <= N; i++){
		memset(d, 0, sizeof(d)); int cnt = 0;
		for(int j = 1; j * j <= i; j++)
			if(i % j == 0){
				d[++cnt] = j;
				if(j != i / j) d[++cnt] = i / j;
			}
		sort(d + 1, d + cnt + 1);
		int temp = 0;
		for(int j = 1; j <= cnt; j++) temp += d[j];
		p[i] = temp - i;
	}
}

void dp(){
	for(int i = 1; i <= s; i++)
		for(int j = s; j >= i; j--)
			f[j] = max(f[j], f[j - i] + p[i]);
}

int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	scanf("%d", &s);
	prework(); dp();
	cout << f[s] << '\n';
	return 0;
}
