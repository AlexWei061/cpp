#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100100
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
char s[MAXN];

int b[MAXN] = { 0 };
int c[MAXN] = { 0 };

int main(){
	n = in;
	for(int  i = 0; i < n; i++) a[i] = in;
	scanf("%s", s);
	sort(a, a + n); a[n] = 2e9;
	int m = -1; int op = 0;
	for(int i = 0; i < n; i++)
		if(i and s[i] == s[i-1]) m++;
	int k = m + 1;
	for(int i = 0; i < n; i++){
		if(i and s[i] == s[i-1]){
			c[i] = op ^= 1; b[i] = a[m--];
		}
		else{
			c[i] = (s[i] == 'R'); b[i] = a[k++];
			if(!i) op = (s[i] == 'R');
		}
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << ' ' << ("LR"[c[i]]) << endl;
	}
	return 0;
}
