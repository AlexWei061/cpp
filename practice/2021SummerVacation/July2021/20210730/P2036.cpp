#include<bits/stdc++.h>
using namespace std;

int n = 0;

struct Ingridient{
    int s;
    int b;
}ingre[15];

int ans = INT_MAX;

void dfs(int i, int s, int b){
    if(i > n){
        if(s == 1 and b == 0){
            return;
        }
        ans = min(abs(s-b), ans);
        return;
    }
    dfs(i + 1, s * ingre[i].s, b + ingre[i].b);
    dfs(i + 1, s, b);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &ingre[i].s, &ingre[i].b);
    }

    dfs(1, 1, 0);

    printf("%d\n", ans);

    /*
    for(int i = 1; i <= n; i++){
        printf("s = %d b = %d\n", ingre[i].s, ingre[i].b);
    }
    */
    return 0;
}

/*

[题目描述]
Perket 是一种流行的美食。为了做好 Perket，厨师必须谨慎选择食材，以在保持传统风味的同时尽可能获得最全面的味道。你有 n 种可支配的配料。
对于每一种配料，我们知道它们各自的酸度 s 和苦度 b。当我们添加配料时，总的酸度为每一种配料的酸度总乘积；总的苦度为每一种配料的苦度的总和。
众所周知，美食应该做到口感适中，所以我们希望选取配料，以使得酸度和苦度的绝对差最小。
另外，我们必须添加至少一种配料，因为没有任何食物以水为配料的。

[输入格式]
第一行一个整数 n，表示可供选用的食材种类数。
接下来 n 行，每行 2 个整数 si 和 bi ，表示第 i 种食材的酸度和苦度

[输出格式]
一行一个整数，表示可能的总酸度和总苦度的最小绝对差。

[输入输出样例]
1
3 10

7

2
3 8
5 8

1

对于所有数据 1 <= n <= 10, 且所有可使用食材全部使用的总苦度和酸度总和小于10^9, 酸度和苦度不同时为 1 和 0

*/