#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

int p = 0;

int f[MAXN] = { 0 };
int ans[MAXN] = { 0 };
int sav[MAXN] = { 0 };

void calc1(){
	memset(sav, 0, sizeof(sav));
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			sav[i + j - 1] += ans[i] * f[j];
	for(int i = 1; i <= 500; i++)
		sav[i + 1] += sav[i] / 10, sav[i] %= 10;
	memcpy(ans, sav, sizeof(ans));
}

void calc2(){
	memset(sav, 0, sizeof(sav));
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			sav[i + j - 1] += f[i] * f[j];
	for(int i = 1; i <= 500; i++)
		sav[i + 1] += sav[i] / 10, sav[i] %= 10;
	memcpy(f, sav, sizeof(f));
}

void solve(int p){
	while(p){
		if(p & 1) calc1();
		p >>= 1; calc2();
	}
}

int main(){
	scanf("%d", &p);
	int d = p * log10(2) + 1;
	cout << d << '\n';
	ans[1] = 1; f[1] = 2; solve(p);
	ans[1] -= 1;
	for(int i = 500; i >= 1; i--)
		if(i != 500 and i % 50 == 0) cout << '\n' << ans[i];
		else cout << ans[i];
	return 0;
}