#include<bits/stdc++.h>
using namespace std;

int head[] = { 0 };
int  ver[] = { 0 };
int  nxt[] = { 0 };                                //next[]
int edge[] = { 0 };
int is_visited[] = { 0 };
int tot = 0;

void addEdge(int x, int y, int z){
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x){                                   //从x开始遍历
    is_visited[x] = 1;                             //x被访问过
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        if(is_visited[y]){                         //如果被访问过
            continue;
        }
        dfs(y);
    }
}

int main(){

    return 0;
}