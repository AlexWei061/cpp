#include<bits/stdc++.h>
using namespace std;

int a, b;

int main(){
    scanf("%d%d", &a, &b);
    double m = a * 1.0 + b / 10.0;
    cout << (int)(m / 1.9) << endl;
    return 0;
}

/*

[题目描述]
班主任给小玉一个任务，到文具店里买尽量多的签字笔。已知一只签字笔的价格是 1 元 9 角，
而班主任给小玉的钱是 a 元 b 角，小玉想知道，她最多能买多少只签字笔呢。

*/