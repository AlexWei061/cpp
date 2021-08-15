#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define VERTICES 9

int head[N] = { 0 };                             //x
int  ver[N] = { 0 };                             //y
int  nxt[N] = { 0 };
int edge[N] = { 0 };
int tot = 0;

int depth[N] = { 0 };

void addEdge(int x, int y, int z){               //加入有向边(x, y)边权为z
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot;
}

void bfs(){
    memset(depth, 0, sizeof(depth));
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    while(q.size() > 0){
        int x = q.front();
        printf("%d ", x);
        q.pop();
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i];
            if(depth[y]){
                continue;
            }
            depth[y] = depth[x] + 1;
            q.push(y);
        }
    }
}

int main(){
    addEdge(1, 2, 0); addEdge(1, 3, 0); addEdge(1, 4, 0);
    addEdge(2, 1, 0); addEdge(2, 5, 0);
    addEdge(3, 1, 0); addEdge(3, 4, 0);
    addEdge(4, 1, 0); addEdge(4, 3, 0); addEdge(4, 6, 0);
    addEdge(5, 2, 0); addEdge(5, 7, 0);
    addEdge(6, 4, 0); addEdge(6, 8, 0);
    addEdge(7, 5, 0); addEdge(7, 8, 0); addEdge(7, 9, 0);
    addEdge(8, 6, 0); addEdge(8, 7, 0);
    addEdge(9, 7, 0);

    bfs();

    printf("\ndepth : ");
    for(int i = 1; i <= VERTICES; i++){
        printf("%d ", depth[i]);
    }
    printf("\n");

    return 0;
}