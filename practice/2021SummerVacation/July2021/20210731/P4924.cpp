#include<bits/stdc++.h>
using namespace std;

int n = 0;
int mmap[505][505] = { 0 };

int m = 0;
struct Operation{
    int x, y;
    int r, z;
}operation[505];

void prework(){
    int a = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mmap[i][j] = a++;
        }
    }
}

int temp[505][505] = { 0 };
void operate(int x, int y, int r, int z){
    memset(temp, 0, sizeof(temp));
    if(z == 0){                                           //顺时针 第i行第j个 变成倒数第i列第j个
        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                temp[x-y+j][x+y-i] = mmap[i][j];
            }
        }

        /*
        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                printf("%d ", temp[i][j]);
            }
            printf("\n");
        }
        */

        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                mmap[i][j] = temp[i][j];
            }
        }
    }

    else{                                                 //逆时针 第i行第j个 变成第i列倒数第j个
        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                temp[x+y-j][y-x+i] = mmap[i][j];
            }
        }

        /*
        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                printf("%d ", temp[i][j]);
            }
            printf("\n");
        }
        */

        for(int i = x-r; i <= x+r; i++){
            for(int j = y-r; j <= y+r; j++){
                mmap[i][j] = temp[i][j];
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    prework();
    
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d%d", &operation[i].x, &operation[i].y, &operation[i].r, &operation[i].z);
        operate(operation[i].x, operation[i].y, operation[i].r, operation[i].z);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", mmap[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*

[题目描述]
Scarlet最近学会了一个数组魔法，她会在 n*n 二维数组上将一个奇数阶方阵按照顺时针或者逆时针旋转90°
首先，Scarlet会把 1 到 n^2 的正整数按照从左往右，从上至下的顺序填入初始的二维数组中，然后她会施放一些简易的魔法
Scarlet既不会什么分块特技，也不会什么Splay套Splay，她现在提供给你她的魔法执行顺序，想让你来告诉她魔法按次执行完毕后的二维数组

[输入格式]
第一行两个整数n, m, 表示方阵大小和魔法施放次数
接下来 m 行, 每行 4 个整数 x, y, r, z 表示在这次魔法中, Scarlet会把以第x行第y列为中心的 2r+1 阶矩阵按照某种时针方向旋转
其中 z = 0 表示顺时针z = 1 表示逆时针。

[输入输出样例]
5 4
2 2 1 0
3 3 1 1
4 4 1 0
3 3 2 1

5 10 3 18 15
4 19 8 17 20
1 14 23 24 25
6 9 2 7 22
11 12 13 16 21

对于 50% 的数据, 满足 r = 1
对于 100% 的数据, 满足 1 <= n, m <= 500, 1 <= x-r <= x+r <= n, 1 <= y-r <= y+r <= n

*/