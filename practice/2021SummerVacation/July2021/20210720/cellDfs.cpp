#include<bits/stdc++.h>
using namespace std;

//P1451

const int px[5] = { 0, 1, 0, -1,  0 };
const int py[5] = { 0, 0, 1,  0, -1 };

int n, m;
char cell[105][105];

void dfs(int x, int y){
	for(int k = 1; k <= 4; k++){
		int i = x + px[k];
		int j = y + py[k];
		if(i >= 1 and i <= n and j >= 1 and j <= m and cell[i][j] != '0'){
			cell[i][j] = '0';
			dfs(i, j);
		}
	}
}

int main(){
	memset(cell, '0', sizeof(cell));
	
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> cell[i][j];
		}
	}
	
	/*
	for(int i = 0;i <= n+1; i++){
		for(int j = 0; j <= m+1; j++){
			cout << cell[i][j];
		}
		puts("");
	}
	*/
	
	int ans = 0;
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(cell[i][j] != '0'){
				cell[i][j] = '0';
				dfs(i, j);
				ans++;
			}
		}
	}
	
	printf("%d", ans);
	return 0;
}

/*
4 10
0234500067
1034560500
2045600671
0000000089
*/
