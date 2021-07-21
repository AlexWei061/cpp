#include<bits/stdc++.h>
using namespace std;

struct Coordinate{
	int x;
	int y;
};

int n                   =   0  ;
int magicSquare[40][40] = { 0 };

Coordinate coor[1600]; 

void work(){                             //预处理coor 
	magicSquare[1][n/2+1] = 1;
	coor[1].x = n / 2 + 1;
	coor[1].y = 1;
}

/*
若 (K-1)第一行但不在最后一列，则将 K填在最后一行， (K-1)所在列的右一列；
若 (K-1)在最后一列但不在第一行，则将 K填在第一列， (K-1)所在行的上一行；
若 (K-1)在第一行最后一列，则将 K填在 (K-1)的正下方；
若 (K-1)既不在第一行，也不在最后一列，如果 (K-1)的右上方还未填数，则将 K填在 (K-1)的右上方，否则将 K填在 (K-1)的正下方。
*/ 

void adjustSquare(){
	int k = 2;                          //1不用处理 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(coor[k-1].y == 1 and coor[k-1].x != n){
				magicSquare[n][coor[k-1].x+1] = k;
				coor[k].x = coor[k-1].x + 1;
				coor[k].y = n;
			}
			else if(coor[k-1].x == n and coor[k-1].y != 1){
				magicSquare[coor[k-1].y-1][1] = k;
				coor[k].x = 1;
				coor[k].y = coor[k-1].y - 1;
			}
			else if(coor[k-1].x == n and coor[k-1].y == 1){
				magicSquare[coor[k-1].y+1][coor[k-1].x] = k;
				coor[k].x = coor[k-1].x;
				coor[k].y = coor[k-1].y + 1;
			}
			else if(coor[k-1].x != n and coor[k-1].y != 1){
				if(magicSquare[coor[k-1].y-1][coor[k-1].x+1] == 0){
					magicSquare[coor[k-1].y-1][coor[k-1].x+1] = k;
					coor[k].x = coor[k-1].x + 1;
					coor[k].y = coor[k-1].y - 1;
				}
				else{
					magicSquare[coor[k-1].y+1][coor[k-1].x] = k;
					coor[k].x = coor[k-1].x;
					coor[k].y = coor[k-1].y + 1;
				}
			}
			k++;
		}
	}
}

int main(){
	scanf("%d", &n);
	work();
	adjustSquare();
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", mmap[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 1; i <= n*n; i++){
		printf("%d's x = %d y = %d\n", i, coor[i].x, coor[i].y);
	}
	*/
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", magicSquare[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
