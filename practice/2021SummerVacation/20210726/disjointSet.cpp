#include<bits/stdc++.h>
using namespace std;

int vertices = 6;
int    edges = 6;

void initialize(int parent[], int rank[]){                                    //parent初始化为-1 parent[i] = -1-->i为根节点
    for(int i = 0; i < vertices; i++){
        parent[i] = -1;
        rank[i] = 0;
    }
}

int findRoot(int node, int parent[]){                                         //找到x的根节点
    int rootNode = node;
    while(parent[rootNode] != -1){
        rootNode = parent[rootNode];
    }
    return rootNode;
}

//1-->union成功
//0-->unio失败(已经在同一个集合中)
bool unionVertices(int node1, int node2, int parent[], int rank[]){           //合并两个点
    int rootNode1 = findRoot(node1, parent);
    int rootNode2 = findRoot(node2, parent);
    if(rootNode1 == rootNode2){                                               //在同一个集合
        return false;
    }
    else{
        if(rank[rootNode1] > rank[rootNode2]){
            parent[rootNode2] = rootNode1;
        }
        else if(rank[rootNode2] > rank[rootNode1]){
            parent[rootNode1] = rootNode2;
        }
        else{
            parent[rootNode2] = rootNode1;
            rank[rootNode1]++;
        }
        return true;
    }
}

int main(){
    int parent[vertices];                                                     //parent[i] = n-->第i个节点的父节点是n
    int rank[vertices] = { 0 };                                               //rank[i] = n-->第i个节点下方树的层数为n
    initialize(parent, rank);

    int gedges[6][2] = 
    {
         { 0, 1 }, { 1, 2 }, { 1, 3 },
         { 2, 4 }, { 3, 4 }, { 2, 5 }
    };

    for(int i = 0; i < edges; i++){
        int node1 = gedges[i][0];
        int node2 = gedges[i][1];
        if(unionVertices(node1, node2, parent, rank) == 0){
            printf("Cycle detected\n");
            return 0;
        } 
    }

    printf("No cycle found\n");

    return 0;
}