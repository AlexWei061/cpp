#include<bits/stdc++.h>
using namespace std;

#define MAXN 205

char a[MAXN], b[MAXN];
int f[MAXN][MAXN] = { 0 };           // f[i][j] A 在 i 且 B 在 j 时的最长公共子序列

/*

f[i][j] = f[i-1][j-1] + 1            (a[i]  = b[j])
        = max(f[i][j-1], f[i-1][j])  (a[i] != b[j])

*/
void dp(){
	int lena = strlen(a + 1);
	int lenb = strlen(b + 1);
	for(int i = 1; i <= lena; i++){
		for(int j = 1; j <= lenb; j++){
			if(a[i] == b[j]){
				f[i][j] = f[i-1][j-1] + 1;
			}
			else{
				f[i][j] = max(f[i][j-1], f[i-1][j]);
			}
		}
	}
}

int main(){
	scanf("%s%s", a + 1, b + 1);

	dp();

	int ans = f[strlen(a+1)][strlen(b+1)];
	printf("%d\n", ans);
	return 0;
}

// 最长公共子序列