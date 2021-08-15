#include<bits/stdc++.h>
using namespace std;

int n = 0;
int m = 0;
int a[100001] = { 1 };

void print(int x){
    for(int i = 1; i <= x-1; i++){
        printf("%d+", a[i]);
    }
    printf("%d\n", a[x]);
}

void dfs(int x){                               //当前项
    for(int i = a[x-1]; i <= m; i++){          //后面的一定比前面的大所以从前一项开始枚举
        //printf("i = %d\n", i);
        if(i == n){
            continue;
        }
        a[x] = i;
        m -= i;
        if(m == 0){
            print(x);
        }
        else{
            dfs(x+1);
        }
        m += i;
    }
}

int main(){
    scanf("%d", &n);
    m = n;
    dfs(1);
    //printf("Hello\n");
    return 0;
}

/*

[题目描述]
任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。现在给你一个自然数n，要求你求出n的拆分成一些数字的和。
每个拆分后的序列中的数字从小到大排序。然后你需要输出这些序列，其中字典序小的序列需要优先输出。

[输入输出样例]
7

1+1+1+1+1+1+1
1+1+1+1+1+2
1+1+1+1+3
1+1+1+2+2
1+1+1+4
1+1+2+3
1+1+5
1+2+2+2
1+2+4
1+3+3
1+6
2+2+3
2+5
3+4

n <= 8  
*/