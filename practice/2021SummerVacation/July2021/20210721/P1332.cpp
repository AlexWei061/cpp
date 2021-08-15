#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 1, 0, -1,  0 };
const int py[] = { 0, 0, 1,  0, -1 };

int n = 0;
int m = 0;
int a = 0;
int b = 0;
int array[505][505]  = { 0 };
int   way[505][505]  = { 0 };

struct qNode{
	int x;
	int y;
	int depth;
}q[100001];

int head = 0;
int tail = 0;

void expand(int x, int y, int step){
	for(int i = 1; i <= 4; i++){
		int nx = x + px[i];
		int ny = y + py[i];
		if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and way[nx][ny] == 0){
			q[tail].x = nx;
			q[tail].y = ny;
			q[tail].depth = step+1;
			array[nx][ny] = min(array[nx][ny], q[tail].depth);
			way[nx][ny] = 1;
			tail++;
		}
	}
}

void bfs(int x, int y){
	head = 1;
	tail = 1;
	way[x][y] = 1;
	array[x][y] = 0;
	q[tail].x = x;
	q[tail].y = y;
	q[tail].depth = 0;
	tail++;
	while(head != tail){
		//printf("%d\n", 1);
		int i = q[head].x;
		int j = q[head].y;
		int step = q[head].depth;
		head++;
		expand(i, j, step);
	}
	memset(way, 0, sizeof(way));
}

int main(){
	memset(array, 127, sizeof(array));
	
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int x, y;
	for(int i = 1; i <= a; i++){
		scanf("%d%d", &x, &y);
		bfs(x, y);
	}
	for(int i = 1; i <= b; i++){
		scanf("%d%d", &x, &y);
		printf("%d\n", array[x][y]);
	}
	
	/*
	scanf("%d%d", &n, &m);
	bfs(1, 1); 
	bfs(5, 4);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}










/*

#include<bits/stdc++.h>
using namespace std;
const int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int N = 2000;
struct node{
    int x, y;
};
int n,m,a,b,tot;
int g[N][N];
int v[N][N];
queue<node>q;
void bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        v[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int x1 = x+dx[i][0],y1 = y+dx[i][1];
            if(x1<1 or y1 < 1 or x1 > n or y1 > m){
                continue;
            }
            if(v[x1][y1]){
                continue;
            }
            v[x1][y1]=1;
            g[x1][y1] = g[x][y] + 1;
            q.push((node){x1, y1});
        }
    }
}
int main(){
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= a; i++){
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
        q.push((node){x, y});
    }
    bfs();
    for(int i = 1; i <= b; i++){
        int x, y;
        cin >> x >> y;
        printf("%d\n", g[x][y]);
    }
    return 0;
}

*/
