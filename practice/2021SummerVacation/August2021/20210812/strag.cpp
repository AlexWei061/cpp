#include<bits/stdc++.h>
using namespace std;

/*

f[i][0]-->第 i 个节点不放士兵时，整个以 i 为根节点的子树需要的士兵的最小值
f[i][1]-->第 i 个节点放士兵时，整个以 i 为根节点的子树需要的士兵的最小值

// 根节点不放那么他的子节点必须放
f[i][0] = \sum_{s \in son(i)} f[s][1]

// 根节点放了那么他的子节点可能放了
f[i][1] = \sum_{s \in son(i)} min{ f[s][0], f[s][1] }

初始化 : 
f[i][0] = 0, f[i][1] = 1

最后答案 : 
ans = min{ f[root][1], f[root][0] }

*/

#define MAXN 1600

vector<int> e[MAXN];
int n = 0;
int f[MAXN][2] = { 0 };
bool isroot[MAXN];

void dp(int x){
    // 初始化
    f[x][0] = 0;
    f[x][1] = 1;

    // 枚举 x 出发的所有边
    for(int i = 0; i < e[x].size(); i++){
        int y = e[x][i];                           // y 是 x 的一个子节点
        dp(y);
        
        // DP 方程 :
        f[x][0] += f[y][1];
        f[x][1] += min(f[y][0], f[y][1]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){             //初始化
        e[i].clear();
        isroot[i] = true;
    }

    for(int i = 0; i < n; i++){
        int x, m;
        scanf("%d%d", &x, &m);
        for(int j = 0; j < m; j++){
            int y = 0;
            scanf("%d", &y);
            e[x].push_back(y);
            isroot[y] = false;
        }
    }

    int root = 0;
    for(int i = 0; i < n; i++){
        if(isroot[i]){
            root = i;
            break;
        }
    }

    dp(root);

    int ans = min(f[root][0], f[root][1]);
    printf("%d\n", ans);

    return 0;
}

/*

[题目描述]
Bob 喜欢玩电脑游戏，特别是战略游戏。但是他经常无法找到快速玩过游戏的办法。现在他有个问题。
他要建立一个古城堡，城堡中的路形成一棵树，他要在这棵树的节点上放置数目最少的士兵，使得这些士兵能够瞭望到所有的路
注意，某个士兵在一个节点上的时候，与该节点相连的所有边都可以被瞭望到
请你表写一个程序，帮 Bob 算出他需要放置的士兵的数量

[输入格式]
输入数据表示一个树
第一行 N 表示节点数
第二行到 N + 1 行每行描述每个节点的信息，依次位节点号 i 和 k(后面有 k 条边与节点 i 相连)
接下来的 k 个数，表示每条边所连接到的节点编号
0 <= n <= 1500

4
0 1 1
1 2 2 3
2 0
3 0

1

----

5
3 3 1 4 2
1 1 0
2 0
0 0
4 0

2

*/