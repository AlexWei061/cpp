#include<bits/stdc++.h>
using namespace std;

/*

f[i][0] = \sum_{s \in son(i)} max{f[s][1], f[s][0]}
f[i][1] = R[i] + \sum_{s \in son(i)} f[s][0]

ans = max{f[root][1], f[root][1]}

*/

#define MAXN 10010

vector<int>  son[MAXN];
int f[MAXN][2] = { 0 };
int v[MAXN] = { 0 };
int h[MAXN] = { 0 };                              // 幸福指数
int n = 0;

void dp(int x){
    f[x][0] = 0;
    f[x][1] = h[x];
    for(int i = 0; i < son[x].size(); i++){
        int y = son[x][i];
        dp(y);
        f[x][0] += max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
    }

    for(int i = 1; i <= n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x] = 1;
        son[y].push_back(x);                                    // x 是 y 的儿子
    }

    int root = 0;
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            root = i;
            break;
        }
    }

    dp(root);

    int ans = max(f[root][0], f[root][1]);
    printf("%d\n", ans);

    return 0;
}

/*

[题目描述]
Ural 大学有 N 个职员，编号为 1 ~ N。他们有从属关系，也就是说他们的关系像一颗一校长为根节点的数。父节点上是子节点的上司。每个职员有一个快乐指数
现在有一个周年庆宴会，要求与会职员的快乐指数最大。但是没有支援愿意和直接上司一起参会

[输入格式]
第一行一个整数 N
接下来的 N 行，第 i + 1 行表示 i 号职员的快乐指数 Ri (-128 <= Ri <= 127)
接下来的 N - 1 行，每行输入一个 L 和 K，表示 K 是 L 的直接上司
组后一行输入 0 0

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0

5

*/