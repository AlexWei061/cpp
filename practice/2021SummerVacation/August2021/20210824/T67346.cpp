#include<bits/stdc++.h>
using namespace std;

const int px[5] = { 0, 1, 0, -1, 0 };
const int py[5] = { 0, 0, 1, 0, -1 };

int n = 0;
int m = 0;

int maze[25][25] = { 0 };
int  way[25][25] = { 0 };

struct Tnode{
	int x, y;
	int depth;
}q[10010];

int head = 0; int tail = 0;

void bfs(Tnode start){
	q[++tail] = start;
	//printf("s.x = %d s.y = %d s.d = %d\n", q[tail].x, q[tail].y, q[tail].depth);
	way[start.x][start.y] = 1;

	while(head < tail){
		head++;
		for(int i = 1; i <= 4; i++){
			int nx = q[head].x + px[i];
			int ny = q[head].y + py[i];
			//printf("	nx = %d ny = %d\n", nx, ny);
			if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and !way[nx][ny] and maze[nx][ny] == 0){
				//printf("		in : nx = %d ny = %d\n", nx, ny);
				q[++tail] = (Tnode){nx, ny, q[head].depth + 1};
				way[nx][ny] = 1;
				if(nx == n and ny == m){
					printf("%d\n", q[tail].depth + 1);
					return;
				}
			}
		}
	}
	printf("%d\n", -1);
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &maze[i][j]);
		}
	}

	bfs((Tnode){1, 1, 0});

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

*/