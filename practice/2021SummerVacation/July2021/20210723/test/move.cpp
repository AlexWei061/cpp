#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n, m;
int  mmap[25][25] = { 0 };
int   way[25][25] = { 0 };
int ttime[25][25] = { 0 };

struct node{
	int x;
	int y;
	int depth;
}q[100001];

int head = 0;
int tail = 0;

void expand(node t){
	for(int i = 1; i <= 4; i++){
		int nx = t.x + px[i];
		int ny = t.y + py[i];
		//printf("	nx = %d ny = %d way[%d][%d] = %d mmap[%d][%d] = %d\n", nx, ny, nx, ny, way[nx][ny], nx, ny, mmap[nx][ny]);
		if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and mmap[nx][ny] == 0 and way[nx][ny] == 0){
			//printf("		jnx = %d ny = %d way[%d][%d] = %d mmap[%d][%d] = %d\n", nx, ny, nx, ny, way[nx][ny], nx, ny, mmap[nx][ny]);
			q[tail++] = (node){nx, ny, t.depth+1};
			way[nx][ny] = 1;
			ttime[nx][ny] = max(t.depth+1, ttime[nx][ny]);
		}
	}
}

void bfs(int x, int y, int depth){
	ttime[x][y] = max(depth, ttime[x][y]);
	way[x][y] = 1;
	head = tail = 1;
	q[tail++] = (node){x, y, depth};
	//printf("q[%d] = (node){x = %d y = %d depth = %d}\n", tail-1, q[tail-1].x, q[tail-1].y, q[tail-1].depth);
	while(head != tail){
		node t = q[head++];
		//printf("t = (node){x = %d y = %d depth = %d}\n", t.x, t.y, t.depth);
		expand(t);
	}
	memset(way, 0, sizeof(way));
}

int findMax(int n, int m, int a[25][25]){
	int mmax = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){
			mmax = max(mmax, a[i][j]);
		}
	}
	//printf("%d\n", mmax);
	return mmax;
}

int main(){
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){
			char c;
			cin >> c;
			if(c == '.'){
				mmap[i][j] = 0;
			}		
			if(c == '#'){
				mmap[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){
			if(mmap[i][j] == 0){
				bfs(i, j, 0);
			}
			//printf("%d ", findMax(n, m, ttime));
			//printf("%d ",);
			//printf("%d ", ans);
		}
	}
	
	ans =  findMax(n, m, ttime);
	printf("%d\n", ans);
	//bfs(3, 1, 0);
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){
			printf("%d ", ttime[i][j]);
		}
		printf("\n");
	}
	*/
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= m; j++){
			printf("%d ", mmap[i][j]);
		}
		printf("\n");
	}	
	*/
	return 0;
}

/*
3 5
...#.
.#.#.
.#...

*/
