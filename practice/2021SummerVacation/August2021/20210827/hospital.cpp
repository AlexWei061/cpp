#include<bits/stdc++.h>
using namespace std;

#define MAXN 101

int n = 0;
int           a[MAXN] = { 0 };
int gragh[MAXN][MAXN] = { 0 };

//int     f[MAXN][MAXN] = { 0 };
void folyd(){
	for(int k = 1;k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				gragh[i][j] = min(gragh[i][k]+gragh[k][j], gragh[i][j]);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	memset(gragh, 0x3f, sizeof(gragh));
	for(int i = 1; i <= n; i++){
		int p = 0, l = 0, r = 0;
		scanf("%d%d%d", &p, &l, &r);
		a[i] = p;
		gragh[i][i] = 0;
		if(l != 0){
			gragh[i][l] = 1;
			gragh[l][i] = 1;
		}
		if(r != 0){
			gragh[i][r] = 1;
			gragh[r][i] = 1;
		}
	}

	folyd();

	int mmin = (int)1e9;
	for(int i = 1; i <= n; i++){
		int s = 0;
		for(int j = 1; j <= n; j++){
			s += gragh[i][j] * a[j];
		}
		mmin = min(mmin, s);
	}

	printf("%d\n", mmin);

	return 0;
}