#include<bits/stdc++.h>
using namespace std;

int n, k;
priority_queue<int> grade;

int main(){
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("\n");
        char c;
        c = getchar();
        if(c == 'I'){
            int x = 0;
            scanf("%d", &x);
            if(cnt < k){
                grade.push(-x);
                cnt++;
            }
            else{
                if(-grade.top() < x){
                    grade.pop();
                    grade.push(-x);
                }
            }
        }
        if(c == 'Q'){
            printf("%d\n", -grade.top());
        }
    }
    return 0;
}

/*

[题目描述]
Tom有一些学生的成绩需要录入，在录入过程中，Tom有时候想要知道已经录入的学生里分数从高到低排名第K的是多少分。现在要你写个程序来回答Tom的问题。

[输入格式]
第一行两个整数N，K。N为操作的次数，K是每次询问的学生名次。

接下来N行，每行是一个操作，有两种：

I X：代表添加一个分数为X的学生，1 ≤ X ≤ 10^9；注意I后有一个空格。

Q：代表一次询问

[输出格式]
对于每个询问输出一行，为排名第K学生的分数。

8 3
I 1
I 2
I 3
Q
I 5
Q
I 4
Q

1
2
3

*/