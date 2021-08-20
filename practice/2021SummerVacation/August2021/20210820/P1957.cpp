#include<bits/stdc++.h>
using namespace std;

int  n = 0;
char c[100];
int  a = 0;
int  b = 0;

void print(char c, int a, int b){
    if(c == 'a'){
        char str[1000];
        sprintf(str, "%d+%d=%d", a, b, a+b);
        printf("%s\n%lu\n", str, strlen(str));
    }
    else if(c == 'b'){
        char str[1000];
        sprintf(str, "%d-%d=%d", a, b, a-b);
        printf("%s\n%lu\n", str, strlen(str));
    }
    else if(c == 'c'){
        char str[1000];
        sprintf(str, "%d*%d=%d", a, b, a*b);
        printf("%s\n%lu\n", str, strlen(str));
    }

}

int main(){
    char lo;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d", c, &a);
        //printf("c = %s\n", c);
        //printf("c[0] = %c\n", c[0]);
        if(c[0] != 'a' and c[0] != 'b' and c[0] != 'c'){
            //printf("enter\n");
            sscanf(c, "%d", &b);
            c[0] = ' ';
            print(lo, b, a);
        }
        else{
            lo = c[0];
            scanf("%d", &b);
            print(c[0], a, b);
        }
    }
    return 0;
}

/*

[题目描述]
王老师正在教简单算术运算。细心的王老师收集了i道学生经常做错的口算题，并且想整理编写成一份练习。 
编排这些题目是一件繁琐的事情，为此他想用计算机程序来提高工作效率。王老师希望尽量减少输入的工作量，
比如 5 + 8 的算式最好只要输入 5 和 8 ，输出的结果要尽量详细以方便后期排版的使用，比如对于上述输入进行处理后输出 5 + 8 = 13 
以及该算式的总长度 6。王老师把这个光荣的任务交给你，请你帮他编程实现以上功能。

[输入格式]
第一行为数值i

接着的i行为需要输入的算式，每行可能有三个数据或两个数据。

若该行为三个数据则第一个数据表示运算类型，a表示加法运算，b表示减法运算，c表示乘法运算，接着的两个数据表示参加运算的运算数。

若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

4
a 64 46
275 125
c 11 99
b 46 64

64+46=110
9
275+125=400
11
11*99=1089
10
46-64=-18
9

*/