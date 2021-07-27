#include<bits/stdc++.h>
using namespace std;

/*P1451*/

const int px[] = { 0, 0, 0, 1, -1 };
const int py[] = { 0, 1, -1, 0, 0 };

int n = 0;
int m = 0;
int cell[105][105] = { 0 };

struct qNode{
	int x;
	int y;
}q[10000], node;

int head = 0;
int tail = 0;

void expand(int x, int y){
	for(int i = 1; i <= 4; i++){
		int nx = x + px[i];
		int ny = y + py[i];
		if(cell[nx][ny] != 0 and nx >= 1 and nx <= n and ny >= 1 and ny <= m){
			q[tail].x = nx;
			q[tail].y = ny;
			tail++;
			cell[nx][ny] = 0;
		}
	}
}

int dfs(int x, int y){
	head = tail = 1;
	q[tail].x = x;
	q[tail].y = y;
	tail++;
	cell[x][y] = 0;
	while(head != tail){
		node = q[head];
		head++;
		expand(node.x, node.y);
	}
}

int main(){
	int ans = 0;
	char c;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c;
			if(c != '0'){
				cell[i][j] = 1;
			}
			else{
				cell[i][j] = 0;
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d", cell[i][j]);
		}
		printf("\n");
	}
	*/
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(cell[i][j] == 1){
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
