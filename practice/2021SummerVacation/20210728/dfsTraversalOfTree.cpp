#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define VERTICES 9

int head[N] = { 0 };
int  ver[N] = { 0 };
int  nxt[N] = { 0 };                               //next[]
int edge[N] = { 0 };
int is_visited[N] = { 0 };
int tot = 0;

int         dfn[N] = { 0 };                       //时间戳
int dfsSequence[N] = { 0 };                       //dfs序
int depth[N] = { 0 };                             //节点的深度
int  size[N] = { 0 };

void addEdge(int x, int y, int z){
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

//runtime complexity : O(M+N)
int m = 0;
int n = 0; 
void dfs(int x){                                   //从x开始遍历
    dfn[++m] = x;
    dfsSequence[++n] = x;
    is_visited[x] = 1;                             //x被访问过
    size[x] = 1;
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        int z = edge[i];
        printf("x = %d y= %d z = %d\n",x, y, z);
        if(is_visited[y]){                         //如果被访问过
            continue;
        }
        depth[y] = depth[x] + 1;
        dfs(y);
        size[x] += size[y];
    }
    dfsSequence[++n] = x;
}

int main(){
    addEdge(1, 4, 0);
    addEdge(4, 6, 0);
    addEdge(4, 3, 0);
    addEdge(3, 9, 0);
    addEdge(1, 7, 0);
    addEdge(1, 2, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 0);
    /*
    int x0 = 2;
    for(int i = head[x0]; i; i = nxt[i]){
        int y0 = ver[i];
        int z0 = edge[i];
        printf("x0 = %d y0 = %d z0 = %d\n", x0, y0, z0);
    }
    */
    dfs(1);
    printf("\n");

    printf("dfn : ");
    for(int i = 1; i <= VERTICES; i++){
        printf("%d ", dfn[i]);
    }
    printf("\n");

    printf("dfs sequence : ");
    for(int i = 1; i <= 2*VERTICES; i++){
        printf("%d ", dfsSequence[i]);
    }
    printf("\n");

    printf("depth : ");
    for(int i = 1; i <= VERTICES; i++){
        printf("%d ", depth[i]);
    }
    printf("\n");

    printf("size : ");
    for(int i = 1; i <= VERTICES; i++){
        printf("%d ", size[i]);
    }
    printf("\n");

    return 0;
}