#include<bits/stdc++.h>
using namespace std;

#define MAXN 405
#define MAXQ 170000
#define INFI 2139062143

const int px[10] = { 0, -2, -1, 1, 2,  2,  1, -1, -2 };
const int py[10] = { 0,  1,  2, 2, 1, -1, -2, -2, -1 };

int n = 0;
int m = 0;
int x = 0;
int y = 0;

int mmap[MAXN][MAXN] = { 0 };
int  way[MAXN][MAXN] = { 0 };

struct Node{
    int x;
    int y;
    int depth;
}q[MAXQ];
int head, tail;

void bfs(int x, int y, int depth){
    memset(mmap, 127, sizeof(mmap));
    mmap[x][y] = depth;
    way[x][y] = 1;
    head = tail = 1;
    q[tail++] = (Node){x, y, depth};
    while(head != tail){
        Node t = q[head++];
        for(int i = 1; i <= 9; i++){
            int nx = t.x + px[i];
            int ny = t.y + py[i];
            int step = t.depth + 1;
            if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and way[nx][ny] == 0){
                way[nx][ny] = 1;
                mmap[nx][ny] = step;
                q[tail++] = (Node){nx, ny, step};
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &x, &y);

    bfs(x, y, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mmap[i][j] == INFI){
                printf("%-5d", -1);
            }
            else{
                printf("%-5d", mmap[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

/*
[题目描述]
有一个n * m的棋盘，在某个点(x, y)上有一个马, 要求你计算马到棋盘上任意一个点最少要走几步

[输入样例]
3 3 1 1

[输出样例]
0    3    2    
3    -1   1    
2    1    4

1 <= x <= n <= 400, 1 <= y <= m <= 400
*/