#include<bits/stdc++.h>
using namespace std;

#define N 1050

int s1, s2, s3, s4;
int A[N] = { 0 };
int B[N] = { 0 };
int C[N] = { 0 };
int D[N] = { 0 };

int f[N] = { 0 };

void scan(){
    scanf("%d%d%d%d", &s1, &s2, &s3, &s4);
    for(int i = 1; i <= s1; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= s2; i++){
        scanf("%d", &B[i]);
    }
    for(int i = 1; i <= s3; i++){
        scanf("%d", &C[i]);
    }
    for(int i = 1; i <= s4; i++){
        scanf("%d", &D[i]);
    }
}

void print(){
    printf("S : ");
    printf("%d %d %d %d", s1, s2, s3, s4);
    printf("\n");

    printf("A : ");
    for(int i = 1; i <= s1; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("B : ");
    for(int i = 1; i <= s2; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("C : ");
    for(int i = 1; i <= s3; i++){
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("D : ");
    for(int i = 1; i <= s4; i++){
        printf("%d ", D[i]);
    }
    printf("\n");
}

int knaspsack(int s, int arr[]){                 //题目可以简化成一个s个物品体积为 m/2的01背包
    //printf("s = %d\n", s);
    int m = 0;                                   //总时间
    //printf("m = %d\n", m);
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= s; i++){
        m += arr[i];
    }
    //printf("m = %d\n", m);
    /* f[j] = max{ f[j], f[j-a[i]] + a[i] } */
    for(int i = 1; i <= s; i++){
        for(int j = m/2; j >= arr[i]; j--){
            f[j] = max(f[j], f[j-arr[i]] + arr[i]);
        }
    }
    return max(f[m/2], m - f[m/2]);
}

int main(){
    scan();

    int n = knaspsack(s1, A) + knaspsack(s2, B) + knaspsack(s3, C) + knaspsack(s4, D);
    printf("%d\n", n);

    //print();
    return 0;
}

/*
[题目背景]
kkksc03 的大学生活非常的颓废，平时根本不学习。但是，临近期末考试，他必须要开始抱佛脚，以求不挂科

[题目描述]
这次期末考试，kkksc03 需要考 44 科。因此要开始刷习题集，每科都有一个习题集，分别有s1, s2, s3, s4道题目
完成每道题目需要一些时间，可能不等(A1, A2, A3, ..., As1,  B1, B2, B3, ..., Bs2,  C1, C2, C3, ..., Cs4,  D1, D2, D3, ..., Ds4)
kkksc03 有一个能力，他的左右两个大脑可以同时计算 2 道不同的题目，但是仅限于同一科。因此，kkksc03 必须一科一科的复习。
由于 kkksc03 还急着去处理洛谷的 bug，因此他希望尽快把事情做完，所以他希望知道能够完成复习的最短时间。

[输入样例]
1 2 1 3		
5
4 3
6
2 4 3
[输出样例]
20

[说明提示]
1 <= s1, s2, s3, s4 <= 20
1 <= A1, A2, A3, ..., As1,  B1, B2, B3, ..., Bs2,  C1, C2, C3, ..., Cs4,  D1, D2, D3, ..., Ds4 <= 60
*/