#include<bits/stdc++.h>
using namespace std;

const int px[5] = { 0, 0, 1, 0, -1 };
const int py[5] = { 0, 1, 0, -1, 0 };

int n, m, t;
int sx, sy;
int fx, fy;

int ans = 0;
int mmap[10][10] = { 0 };
int  way[10][10] = { 0 };

int dfs(int x, int y){
    way[x][y] = 1;
    if(x == fx and y == fy){
        ans++;
    }
    for(int i = 1; i <= 4; i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx >= 1 and x <= n and ny >= 1 and ny <= m and way[nx][ny] == 0 and mmap[nx][ny] == 0){
            way[nx][ny] = 1;
            dfs(nx, ny);
            way[nx][ny] = 0;
        }
    }
    return -1;
}

int main(){
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    for(int i = 1; i <= t; i++){
        int tempx, tempy;
        scanf("%d%d", &tempx, &tempy);
        mmap[tempx][tempy] = 1;
    }

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", mmap[i][j]);
        }
        printf("\n");
    }
    */
    dfs(sx, sy);
    printf("%d\n", ans);
    return 0;
}

/*

[题目描述]
给定一个N*M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。给定起点坐标和终点坐标
问: 每个方格最多经过1次，有多少种从起点坐标到终点坐标的方案。在迷宫中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍

[输入格式]
第一行N、M和T，N为行，M为列，T为障碍总数。第二行起点坐标SX,SY，终点坐标FX,FY。接下来T行，每行为障碍点的坐标

[输入输出样例]
2 2 1
1 1 2 2
1 2

1

1 <= N, M <= 5

*/