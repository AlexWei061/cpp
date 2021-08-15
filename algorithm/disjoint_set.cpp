#include<bits/stdc++.h>
using namespace std;

#define N 6

/*
disjiont set 并查集
    检查图中是否有环
*/

void initialise(int parent[], int rank[]){
    for(int i = 0; i < N; i++){
        parent[i] = -1;
        rank[i] = 0;
    }
}

int find_root(int x, int parent[]){
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

/* 
True - union successfully
False - union failes(x and y belong to the same set so a cycle is found)
*/
bool union_vertices(int x, int y, int parent[], int rank[]){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root == y_root){
        return false;
    }
    else{
        if (rank[x_root] > rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[y_root] > rank[x_root]){
            parent[x_root] = y_root;
        }
        else{
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return true;
    }
}

int main(){
    int parent[N] = { 0 };
    int rank[N] = { 0 };
    initialise(parent, rank);

    int gragh1[N][2] = {
        {0, 1},
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {2, 5}
    };

    int gragh2[5][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    for(int i = 0; i < N; i++){
        int x = gragh1[i][0];
        int y = gragh1[i][1];
        if(union_vertices(x, y, parent, rank) == 0){
            printf("Gragh1 Cycle detected\n");
            exit(0);
        }
    }
    printf("Gragh1 No cycles found\n");
    return 0;
}