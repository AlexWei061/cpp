#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000

char a[MAXN];
char b[MAXN];

int nxt[MAXN] = { 0 };
int   f[MAXN] = { 0 };

void KMP(int n, int m){
	nxt[1] = 0;
	for(int i = 2, j = 0; i <= n; i++){
		while(j > 0 and a[i] != a[j + 1])
			j = nxt[j];
		if(a[i] == a[j + 1])
			j++;
		nxt[i] = j;
	}
	
	for(int i = 1, j = 0; i <= m; i++){
		while(j > 0 and b[i] != a[j + 1])
			j = nxt[j];
		if(b[i] == a[j + 1])
			j++;
		f[i] = j;	
	}
}

int main(){
	scanf("%s%s", b + 1, a + 1);
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	
	KMP(n, m);
	
	for(int i = 1; i <= m; i++){
		if(f[i] == n) printf("%d\n", i - n + 1);
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", nxt[i]);
	}
	
	return 0;
}
