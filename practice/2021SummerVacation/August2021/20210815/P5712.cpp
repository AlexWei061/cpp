#include<bits/stdc++.h>
using namespace std;

int n = 0;

void print(int n){
    if(n == 0){
        printf("Today, I ate 0 apple.\n");
    }
    else if(n == 1){
        printf("Today, I ate 1 apple.\n");
    }
    else{
        printf("Today, I ate %d apples.\n", n);
    }
}

int main(){
    scanf("%d", &n);
    print(n);
    return 0;
}

/*

[题目描述]
八尾勇喜欢吃苹果。她今天吃掉了 x(0 ≤ x ≤ 100) 个苹果。英语课上学到了 apple 这个词语，想用它来造句。如果她吃了 1 个苹果，
就输出 Today, I ate 1 apple.；如果她没有吃，那么就把 1 换成 0；如果她吃了不止一个苹果，别忘了 apple 这个单词后面要加上代表复数的 s。
你能帮她完成这个句子吗？

*/