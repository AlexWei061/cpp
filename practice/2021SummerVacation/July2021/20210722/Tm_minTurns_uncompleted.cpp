#include<bits/stdc++.h>
using namespace std;

//dire : 1-->right | 2-->down | 3-->left | 4-->up
const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n = 0;
int m = 0;
int mmap[105][105] = { 0 };
int  way[105][105] = { 0 };

int sx, sy;
int dx, dy;

struct node{
    int x;                 //坐标
    int y;
    int depth;             //转弯次数
    int dire;              //上一步的方向
}q[10001];
int head = 0;
int tail = 0;

void expand(node t){
    for(int i = 1; i <= 4; i++){
        if(t.dire == i){
            continue;
        }
        int nx = t.x + px[i];
        int ny = t.y + py[i];
        while(/*nx >= 1 and nx <= n and ny >= 1 and ny <= m and */mmap[nx][ny] == 0 and way[nx][ny] == 0){
            q[tail++] = (node){nx, ny, t.depth+1, i};
            way[nx][ny] = 1;
        }
    }
}

int bfs(node t){
    memset(way, 0, sizeof(way));
    head = tail = 1;
    q[tail++] = (node){t.x, t.y, t.depth, t.dire};
    way[t.x][t.y] = 1;
    while(head != tail){
        node n = q[head++];
        if(n.x == dx and n.y == dy){
            return n.depth-1;
        }
        else{
            expand(n);
        }
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &mmap[i][j]);
        }
    }
    scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
    
    printf("ans = %d\n", bfs((node){sx, sy, 0, -1}));

    return 0;
}

/*
                                T3:最少转弯问题 
 题目描述 
 给出一张地图，这张地图被分为n*m(n,m<=100)个方块，任何一个方块不是平地就是高山。 
平地可以通过，高山则不能。现在你处在地图的（x1,y1 ）这块平地，问你至少需要拐几个 
弯才能达到目的地（x2 ，y2 ）？你只能沿着水平和垂直方向的地平上行进，拐弯次数就等于 
行进方向的改变（从水平到垂直或从垂直到水平）的次数。如图所示，最少的拐弯次数为5 。 

 输入 
 第1 行： n m 
 第2 至n+1 行：整个地图地形描述（0 ：空地；1：高山） 
 第2 行地形描述为：1 0 0 0 0 1 0 
 第3 行地形描述为：0 0 1 0 1 0 0 
 …… 
 第n+2 行：x1 y1 x2 y2(分别为起点、终点坐标) 
 输出 
 s( 即最少的拐弯次数) 
 样例输入 
 5 7 
 1 0 0 0 0 1 0 
 0 0 1 0 1 0 0 
 0 0 0 0 1 0 1 
 0 1 1 0 0 0 0 
 0 0 0 0 1 1 0 
 1 3 1 7 
 样例输出 
 5
 */ 

