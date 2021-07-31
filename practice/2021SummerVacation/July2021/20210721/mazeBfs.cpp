#include<bits/stdc++.h>
using namespace std;

const int px[5] = { 0, 0, 1,  0, -1 };
const int py[5] = { 0, 1, 0, -1,  0 };

int r = 0;
int c = 0;
int maze[100][100] = { 0 };

struct qNode{
	int x;
	int y;
	int depth;
}q[1010];

int head = 0;
int tail = 0;

void expand(int xx, int yy, int step){
	for(int i = 1; i <= 4; i++){
		int nx = xx + px[i];
		int ny = yy + py[i];
		if(maze[nx][ny] == 0 /*可以继续走*/ and (nx >= 1 and nx <= r and ny >= 1 and ny <= c) /*不越界*/ ){
			q[tail].x = nx;                      //扩展根节点 
			q[tail].y = ny;
			q[tail].depth = step + 1;
			tail++;
			maze[nx][ny] = 1;                   //标记走过 
		}
	}
}

int bfs(int xx, int yy){
	head = 1;                           //队列置空 
	tail = 1; 
	/*起点入队-----------*/
	q[tail].x = xx;
	q[tail].y = yy;
	q[tail].depth = 1;
	printf("q[tail].x = %d q[tail].y = %d q[tail].depth = %d\n", q[tail].x, q[tail].y, q[tail].depth);
	tail++;
	printf("%d\n", tail);
	/*------------------*/
	while(head != tail){                //队列不为空 
		int i = q[head].x;              //读入队首 
		int j = q[head].y;
		int step = q[head].depth;
		printf("i = %d j = %d step = %d\n", i, j, step);
		head++;                         //删除队首
		printf("%d\n", head);
		if(i == r and j == c){          //到达终点输出答案 
			return step;
		}
		else{                           //未到达终点继续扩展 
			expand(i, j, step); 
		} 
	}
	return -1;                          //while中没有return说明无法到达终点 
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", &maze[i][j]);
		}
	}
	
	printf("%d", bfs(1, 1));
	
	return 0;
}


/*

6 9
0 0 0 1 1 0 0 0 1
0 1 0 0 0 0 1 0 1
0 1 0 1 0 1 1 0 1
0 1 0 1 0 0 0 0 0
0 1 1 0 1 1 0 1 0
0 0 0 0 0 0 0 1 0

14

*/


