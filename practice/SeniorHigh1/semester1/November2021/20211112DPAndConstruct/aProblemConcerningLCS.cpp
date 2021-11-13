#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000

char a[MAXN];

int main(){
	scanf("%s", a + 1); int n = strlen(a + 1);
	int A = 0; int T = 0; int C = 0; int G = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == 'A') A++;
		else if(a[i] == 'T') T++;
		else if(a[i] == 'C') C++;
		else G++;
	int x = min(min(A, T), min(C, G));
	if(x == A) for(int i = 1; i <= n; i++) cout << 'A';
	else if(x == T) for(int i = 1; i <= n; i++) cout << 'T';
	else if(x == C) for(int i = 1; i <= n; i++) cout << 'C';
	else for(int i = 1; i <= n; i++) cout << 'G';
	puts("");
	return 0;
}