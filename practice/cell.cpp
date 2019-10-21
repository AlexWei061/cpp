#include<iostream>
#include<string.h>
using namespace std;

/*
    [题目描述]
    一矩形阵列有数字0到9组成，数字1到9表示细胞，细胞的定义是为沿细胞数字上下左右还是细胞数字则为同一细胞，求给定矩形阵列的细胞个数
    
    [输入格式]
    第1行有2个数字n, m，分别表示n行m列矩阵(1 <= n, M <= 100)
    第2~n+1行为输入矩阵，每个矩阵字符都在0~9之间，字符之间没有换行或空格符

    [输出格式]
    输出一个整数ans，细胞的个数

    [输入样例]cell.in
    4 10
    0234500067
    1034560500
    2045600671
    0000000089
  
    [输出样例]cell.out
    4
*/

int n, m;                                                 //创建m，n
int ans = 0;                                              //创建ans = 0 
int way[105][105];                                        //做搜索标记
char Map[105][105];                                       //创建所给出矩阵(因为没有空格，所以要用char型)
const int fx[5] = {0,-1,0,1, 0};                          //行增量
const int fy[5] = {0, 0,1,0,-1};                          //列增量

int dfs(int x, int y){                                    //搜索细胞函数
    for (int i = 1; i <= 4; i++){
        int nx = x + fx[i];                               //增加x
        int ny = y + fy[i];                               //增加y
        if (nx < 1 || nx > n || ny < 1 || ny > m){        //如果越界，枚举下一个点
            continue;
        }
        if (way[nx][ny] != 1 && Map[nx][ny] != '0'){      //若没搜索过
            way[nx][ny] = 1;                              //标记搜索过
            dfs(nx,ny);                                   //从点(nx,ny)开始递归
        }
    }
}

int main(){
    freopen("cell.in","r",stdin);
    freopen("cell.out","w",stdout);
    printf("program started");
    scanf("%d%d\n",&n,&m);                                //输入n，m
    for(int i = 1; i <= n; i++){
        scanf("%s",Map[i]+1);                             //把一整行当做一个string输入(行和列都从1开始)
    }
    memset(way,0,sizeof(way));                            //初始化way
    //枚举所有点
    for (int i = 1; i <= n; i++){                         //枚举行
        for (int j = 1; j <= m; j++){                     //枚举列
            if (Map[i][j] != '0' && way[i][j] != 1){      //若位置way[i][j]是细胞数字且没被搜索过
                way[i][j] = 1;                            //标记搜索
                ans++;                                    //搜索到了一个细胞
                dfs(i,j);                                 //搜索整个细胞并标记搜索
            }
        }
    }
    printf("%d\n",ans);                                   //输出ans
    return 0;
}