#include<bits/stdc++.h>
using namespace std;

#define INFI 2139062143

const int px[5] = { 0, 0, 1, 0, -1 };
const int py[5] = { 0, 1, 0, -1, 0 };

int M = 0;
struct Aerolite{
    int x;
    int y;
    int t;
}aero[50500];

int mmap[500][500] = { 0 };
int  way[500][500] = { 0 };

void prework(){
    memset(mmap, 127, sizeof(mmap));
    for(int i = 1; i <= M; i++){
        int x = aero[i].x; int y = aero[i].y; int tme = aero[i].t;
        //printf("x = %d y = %d time = %d\n", x, y, tme);
        if(mmap[x][y]  > tme){
            //printf("    map[%d][%d] = %d\n", x, y, tme);
            mmap[x][y] = tme;
        }
        for(int j = 1; j <= 4; j++){
            int xx = x + px[j]; int yy = y + py[j]; int tt = tme+1;
            //printf("    x = %d y = %d time = %d\n", xx, yy, tt);
            if(xx >= 0 and yy >= 0 and mmap[xx][yy] > tt){                           //在第一象限
                //printf("        map[%d][%d] = %d\n", xx, yy, tt);
                mmap[xx][yy] = tt;
            } 
        }
    }
}

struct Node{
    int x;
    int y;
    int depth;
}q[100001];

int bfs(){
    queue<Node> q;
    way[0][0] = 1;
    q.push((Node){0, 0, 0});
    while(!q.empty()){
        Node t = q.front();
        q.pop();
        printf("x = %d y = %d depth = %d\n", t.x, t.y, t.depth);
        for(int i = 1; i <= 4; i++){
            int nx = t.x + px[i];
            int ny = t.y + py[i];
            int step = t.depth + 1;
            printf("    x = %d y = %d depth = %d\n", nx, ny, step);
            if(nx >= 0 and ny >= 0 and way[nx][ny] == 0 and mmap[nx][ny] > step){
                if(mmap[nx][ny] == INFI){
                    return step;
                }
                printf("        x = %d y = %d depth  %d\n", nx, ny, step);
                q.push((Node){nx, ny, step});
                way[nx][ny] = 1;
            }            
        }
    }
    return -1;
}

int main(){
    scanf("%d", &M);
    for(int i = 1; i <= M; i++){
        scanf("%d%d%d", &aero[i].x, &aero[i].y, &aero[i].t);
    }

    prework();

    printf("%d\n", bfs());
    /*
    for(int i = 1; i <= M; i++){
        printf("x = %d y = %d t = %d\n", aero[i].x, aero[i].y, aero[i].t);
    }
    printf("\n");
    */

    /*
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            printf("%-10d ", mmap[i][j]);
        }
        printf("\n");
        }
    */
    return 0;
}

/*

Bessie hears that an extraordinary meteor shower is coming; reports say that these meteors will crash into earth and destroy anything
they hit. Anxious for her safety, she vows to find her way to a safe location (one that is never destroyed by a meteor) .
She is currently grazing at the origin in the coordinate plane and wants to move to a new,
safer location while avoiding being destroyed by meteors along her way.

The reports say that M meteors (1 ≤ M ≤ 50,000) will strike, with meteor i will striking point (Xi, Yi) (0 ≤ Xi ≤ 300; 0 ≤ Yi ≤ 300)
at time Ti (0 ≤ Ti  ≤ 1,000). Each meteor destroys the point that it strikes and also the four rectilinearly adjacent lattice points.

Bessie leaves the origin at time 0 and can travel in the first quadrant and parallel to the axes at the rate of one distance
unit per second to any of the (often 4) adjacent rectilinear points that are not yet destroyed by a meteor.
She cannot be located on a point at any time greater than or equal to the time it is destroyed).

Determine the minimum time it takes Bessie to get to a safe place.

[题目描述]
贝茜听说了一个骇人听闻的消息：一场流星雨即将袭击整个农场，由于流星体积过大，它们无法在撞击到地面前燃烧殆尽，
届时将会对它撞到的一切东西造成毁灭性的打击。很自然地，贝茜开始担心自己的安全问题。以 Farmer John 牧场中最聪明的奶牛的名誉起誓，
她一定要在被流星砸到前，到达一个安全的地方(也就是说，一块不会被任何流星砸到的土地)。如果将牧场放入一个直角坐标系中，
贝茜现在的位置是原点，并且，贝茜不能踏上一块被流星砸过的土地。 根据预报，一共有 M 颗流星 (1 <= M <= 50000)会坠落在农场上
其中第i颗流星会在时刻 Ti (0 <= Ti <= 1000)砸在坐标为(Xi, Yi)(0 <= Xi, Yi <= 300)的格子里。
流星的力量会将它所在的格子，以及周围 44 个相邻的格子都化为焦土，当然贝茜也无法再在这些格子上行走。

贝茜在时刻 0 开始行动，它只能在第一象限中，平行于坐标轴行动，每 1 个时刻中，她能移动到相邻的（一般是 4 个）格子中的任意一个，
当然目标格子要没有被烧焦才行。如果一个格子在时刻 t 被流星撞击或烧焦，那么贝茜只能在 t 之前的时刻在这个格子里出现。 
贝西一开始在(0,0)。
请你计算一下，贝茜最少需要多少时间才能到达一个安全的格子。如果不可能到达输出 -1。

[输入样例]
4
0 0 2
2 1 2
1 1 2
0 3 5

[输出样例]
5
*/