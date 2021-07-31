#include<bits/stdc++.h>
using namespace std;

/*edge(x, y) = z(value)*/
int head[] = { 0, 1, 3, 4, 0, 6, 0, 0 };         //x
int  ver[] = { 0, 2, 3, 5, 5, 4, 1, 0 };         //y
int  nxt[] = { 0, 0, 0, 2, 0, 0, 5, 0 };
int edge[] = { 0 };                              //边权
int tot = 0;                                     //总边数

void addEdge(int x, int y, int z){               //加入有向边(x, y)边权为z
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot;
}

int main(){
    //遍历从x出发的所有边
    tot = 6;
    addEdge(1, 3, 0);
    int x0 = 1;
    for(int i = head[x0]; i; i = nxt[i]){
        int y0 = ver[i];
        int z0 = edge[i];
        printf("x0 = %d y0 = %d z0 = %d\n", x0, y0, z0);
    }

    int x1 = 1;
    for(int i = head[x1]; i; i = nxt[i]){
        int y1 = ver[i];
        int z1 = edge[i];
        printf("x1 = %d y1 = %d z1 = %d\n", x1, y1, z1);
    }

    return 0;
}