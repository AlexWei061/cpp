#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n, m;
int mmap[55][55] = { 0 };

int way[55][55] = { 0 };
int ttime[55][55] = { 0 };

struct Node{
	int x;
	int y;
	int depth;
};

queue<Node> q;

void bfsForFlood(int x, int y){
	ttime[x][y] = 0;
	way[x][y] = 1;
	q.push((Node){x, y, 0});
	while(!q.empty()){
		Node t = q.front();
		q.pop();
		for(int i = 1; i <= 4; i++){
			int nx = t.x + px[i];
			int ny = t.y + py[i];
			if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and way[nx][ny] == 0 and mmap[nx][ny] == 0){
				q.push((Node){nx, ny, t.depth+1});
				ttime[nx][ny] = t.depth+1;
				way[nx][ny] = 1;
			}
		}
	}
	memset(way, 0, sizeof(way));
}

int bfsForHYC(int sx, int sy, int dx, int dy){
	way[sx][sy] = 1;
	q.push((Node){sx, sy, 0});
	while(!q.empty()){
		Node t = q.front();
		q.pop();
		if(t.x == dx and t.y == dy){
			return t.depth;
		}
		else{
			for(int i = 1; i <= 4; i++){
				int nx = t.x + px[i];
				int ny = t.y + py[i];
				if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and way[nx][ny] == 0 and mmap[nx][ny] == 0 and ttime[nx][ny] > t.depth+1){
					q.push((Node){nx, ny, t.depth+1});
					way[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

int main(){
	int sx, sy, dx, dy, fx, fy;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;
			if(c == '.'){                 //能过 
				mmap[i][j] = 0;
			}
			else if(c == 'X'){            //不能过
				mmap[i][j] = 1; 
			}
			else if(c == 'S'){            //人的起点 
				mmap[i][j] = 0;
				sx = i;
				sy = j;		
			}
			else if(c == 'D'){            //终点 
				mmap[i][j] = 0;
				dx = i;
				dy = j; 
			}
			else if(c == '*'){            //洪水起点 
				mmap[i][j] = 0;
				fx = i;
				fy = j;
			}
		}
	}
	
	bfsForFlood(fx, fy);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", ttime[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	bfsForFlood(sx, sy);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", ttime[i][j]);
		}
		printf("\n");
	}
	
	cout << bfsForHYC(sx, sy, dx, dy) << endl;
	
	return 0;
}



/*
3 6
D...*.
.X.X..
....S.
*/
