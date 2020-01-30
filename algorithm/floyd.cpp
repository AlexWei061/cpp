#include<bits/stdc++.h>
using namespace std;

/*
Dynamic transfer equation : 
    A^k[i, j] = min{ (A^k-1[i, k] + A^k-1[k, j]), A^k-1[i, j]}
*/

#define N    4
#define INFI 65535

void floyd(int gragh[][N + 1]){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                gragh[i][j] = min(gragh[i][j],gragh[i][k] + gragh[k][j]);
            }
        }
    }
}

int main(){
    int a[][N + 1] = 
    {  /* 0  1  2     3     4 */
/*0*/   { 0, 0, 0,    0,    0    },
/*1*/   { 0, 0, 3,    INFI, 7    },
/*2*/   { 0, 8, 0,    2,    INFI },
/*3*/   { 0, 5, INFI, 0,    1    },
/*4*/   { 0, 0, INFI, INFI, 0    }
    };
    floyd(a);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}






/*#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

#define VERTEX_NUM 4
int M = 65535;
//all pair shortest path
static int graph[][VERTEX_NUM+1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 3, M, 7},
    {0, 8, 0, 2, M},
    {0, 5, M, 0, 1},
    {0, 2, M, M, 0}
};

void all_shortest_path(int g[][VERTEX_NUM+1], int vertex_num)
{
    for (int i = 1; i <= vertex_num; i++)
    {
        for (int j = 1; j <= vertex_num; j++)
        {
            for(int k = 1; k <= vertex_num; k++)
            {
                if(i!=k)
                {
                    if(g[i][j] > (g[i][k]+g[k][j]))
                    {
                        g[i][j] = g[i][k]+g[k][j];
                    }
                }
            }
        }   
    }
}

int main()
{
    all_shortest_path(graph, VERTEX_NUM);

    for (int i = 1; i <= VERTEX_NUM; i++)
    {
        for (int j = 1; j <= VERTEX_NUM; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}*/
