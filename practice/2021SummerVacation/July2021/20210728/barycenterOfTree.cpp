#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define VERTICES 9

/*
对于一个节点x，如果我们把它从树上删掉，那么原来的树可能会被分成若干个不相连的部分，其中每一部分都是一棵子树
设maxPart(x)表示在删除节点x后产生的子树中，最大的一个的大小。
使maxPart()函数取到最小的节点p就是这棵树的重心
maxPart(x) = max{ max(size[x的子节点们]), VERTICES-size[x] }
*/

int head[N] = { 0 };
int  ver[N] = { 0 };
int  nxt[N] = { 0 };                               //next[]
int edge[N] = { 0 };
int is_visited[N] = { 0 };
int tot = 0;

int size[N] = { 0 };
int ans = N;
int pos = 0;

void addEdge(int x, int y, int z){
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x){
    is_visited[x] = 1;
    size[x] = 1;
    int maxPart = 0;
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        if(is_visited[y]){
            continue;
        }
        dfs(y);
        size[x] += size[y];                        //从子节点向父节点递推
        maxPart = max(maxPart, size[y]);
    }
    maxPart = max(maxPart, VERTICES-size[x]);
    if(maxPart < ans){
        ans = maxPart;                             //记录ans对应的maxPart的值
        pos = x;                                   //记录重心
    }
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

    dfs(1);

    printf("size : ");
    for(int i = 1; i <= VERTICES; i++){
        printf("%d ", size[i]);
    }
    printf("\n");

    printf("pos = %d\n", pos);

    return 0;
}