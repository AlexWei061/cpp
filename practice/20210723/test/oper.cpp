#include<bits/stdc++.h>
using namespace std;

int n = 0;
char S[400001];
int q = 0;
int t, a, b;

void process(int t, int a, int b){
	if(t == 1){
		swap(S[a], S[b]);
	}
	if(t == 2){
		for(int i = 1; i <= n; i++){
			swap(S[i], S[i+n]);
		}
	}
}

int main(){
	freopen("oper.in", "r", stdin);
	freopen("oper.out", "w", stdout);
	scanf("%d", &n);
	scanf("\n");
	for(int i = 1; i <= n; i++){
		scanf("%c", &S[i]);
	}
	for(int i = n+1; i <= 2*n; i++){
		scanf("%c", &S[i]);
	}
	
	scanf("%d", &q);
	
	for(int i = 1; i <= q; i++){
		scanf("%d%d%d", &t, &a, &b);
		process(t, a, b);
	}
	
	//process(2, 0, 0);
		
	for(int i = 1; i <= 2*n; i++){
		printf("%c", S[i]);
	}
	
	return 0;
}
