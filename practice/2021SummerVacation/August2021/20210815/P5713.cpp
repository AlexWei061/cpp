#include<bits/stdc++.h>
using namespace std;

/*

设题目数量为 n 
Local : 5n
Luogu : 3n + 11

5n > 3n + 11
2n > 11
n  > 5.5

所以在 n > 5.5 时 在 luogu 更快

*/

int n = 0;

int main(){
    scanf("%d", &n);
    if(n >= 6){
        printf("Luogu\n");
    }
    else{
        printf("Local\n");
    }
    return 0;
}

/*

[题目描述]
在洛谷上使用团队系统非常方便的添加自己的题目。如果在自己的电脑上配置题目和测试数据，每题需要花费时间 5 分钟；
而在洛谷团队中上传私有题目，每题只需要花费 3 分钟，但是上传题目之前还需要一次性花费 11 分钟创建与配置团队。
现在要配置 n(n ≤ 100) 道题目，如果本地配置花费的总时间短，请输出 Local，否则输出 Luogu。

*/