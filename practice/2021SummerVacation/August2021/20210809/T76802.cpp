#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int trie[MAXN*31][5] = { 0 };                            // 31 位 2 进制数，每个节点为 0 或 1
int Array[MAXN] = { 0 };
int n = 0;
int ans = 0;
int tot = 1;

int insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int t = x >> i & 1;                              // 二进制数 x 的第 i 位
        if(!trie[p][t]){
            trie[p][t] = ++tot;
        }
        p = trie[p][t];
    }
}

int sreach(int x){
    int p = 0;
    int temp = 0;
    for(int i = 30; i >= 0; i--){
        int t = x >> i & 1;
        if(trie[p][t^1]){                               // t^1 --> 1 变 0, 0 变 1 贪心:找相反的位置做异或运算
            p = trie[p][t^1];                           // 走相反的位置 (贪心)
            temp = temp + (1 << i);                     // 叠加异或结果
        }
        else{
            p = trie[p][t];
        }
    }
    return temp;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &Array[i]);
        insert(Array[i]);
        ans = max(ans, sreach(Array[i]));
    }

    printf("%d\n", ans);
    return 0;
}


/*

在给定 N 个整数 A1, A2, ..., AN 中选出两个数进行 xor 运算 , 得到的结果最大是多少?

[输入格式]
第一行输入一个整数 N
第二行输入 N 个整数 A1, A2, ..., AN

[输出格式]
输出一个整数表示答案

3
1 2 3

3

N <= 10^5
0 <= Ai < 2^31

*/