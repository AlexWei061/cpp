#include<bits/stdc++.h>
using namespace std;

int m, t, s;

int main(){
    scanf("%d%d%d", &m, &t, &s);
    int ans = 0;

    if(t == 0){
        ans = 0;
    }
    else{
        if(s % t == 0){
            ans = max(m - (s / t), 0);
        }
        else{
            ans = max(m - (s / t) - 1, 0);
        }
    }

    printf("%d\n", ans);

    return 0;
}

/*

八尾勇喜欢吃苹果。她现在有 m(m ≤ 100) 个苹果，吃完一个苹果需要花费 t(0 ≤ t ≤ 100) 分钟，
吃完一个后立刻开始吃下一个。现在时间过去了 s(s ≤ 10000) 分钟，请问她还有几个完整的苹果？

*/