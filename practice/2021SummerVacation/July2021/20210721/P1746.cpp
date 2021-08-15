#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n = 0;
int mmap[1001][1001] = { 0 };

int sx, sy;
int dx, dy;

struct Node{
	int x;
	int y;
	int depth;
};

queue<Node> q;

int bfs(int x, int y){
	q.push((Node){x, y, 1});
	mmap[x][y] = 1;
	//printf("x = %d y = %d depth = %d\n", q.front().x, q.front().y, q.front().depth);
	while(!q.empty()){
		Node t = q.front();
		q.pop();
		//printf("t.x = %d t.y = %d t.depth = %d\n", t.x, t.y, t.depth);
		if(t.x == dx and t.y == dy){
			return t.depth-1;
		}
		else{
			for(int i = 1; i <= 4; i++){
				int nx = t.x + px[i];
				int ny = t.y + py[i];
				//printf("	t.x = %d t.y = %d px[i] = %d py[i] = %d nx = %d ny = %d\n",t.x, t.y, px[i], py[i], nx, ny);
				if(nx >= 1 and nx <= n and ny >= 1 and ny <= n and mmap[nx][ny] == 0){
					//printf("	Jnx = %d ny = %d\n", nx, ny);
					q.push((Node){nx, ny, t.depth+1});
					mmap[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			mmap[i][j] = c - 48;
		}
	}
	scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", mmap[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d", bfs(sx, sy));
	
	return 0;
}
