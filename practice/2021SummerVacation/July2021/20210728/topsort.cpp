#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define VERTICES 9
#define EDGES 10

/*
拓扑排序 : 
给定一个有向无环图，若一个由图中所有点构成的序列A满足: 对于图中的每条边(x, y), x在A中都出现在y之前
则成A使该有向无环图的一个拓扑序，求解拓扑序的过程就叫做拓扑排序
*/

int head[N] = { 0 };
int  ver[N] = { 0 };
int  nxt[N] = { 0 };
int tot = 0;

int degree[N] = { 0 };                                      //入度 : degree[x]-->以节点x为终点的有向边的条数被称为x的入度
int A[N] = { 0 };                                           //建立空的拓扑序A
int cnt = 0;

void addEdge(int x, int y){
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    degree[y]++;                                            //预处理degree[]
}

//拓扑排序
void topsort(){
    queue<int> q;
    for(int i = 1; i <= VERTICES; i++){                     //把degree = 0的点入队
        if(degree[i] == 0){
            q.push(i);
        }
    }

    while(q.size() != 0){                                   //取出队头结点x
        int x = q.front();
        q.pop();
        A[++cnt] = x;                                       //把x加入A的尾部
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i];
            if(--degree[y] == 0){                           //对于从x出发的每条边(x, y), 把degree[y]减一. 若减为零则把y入队
                q.push(y);
            }
        }
    }
}

int main(){
    addEdge(1, 4);
    addEdge(4, 6);
    addEdge(4, 3);
    addEdge(3, 9);
    addEdge(1, 7);
    addEdge(1, 2);
    addEdge(2, 5);
    addEdge(2, 8);

    topsort();

    printf("A[] : ");
    for(int i = 1; i <= cnt; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}