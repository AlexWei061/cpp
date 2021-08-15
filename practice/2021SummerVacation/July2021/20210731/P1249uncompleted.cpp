#include<bits/stdc++.h>
using namespace std;

#define MANN 10001

/*

思路 :
ln(a) + ln(b) = ln(a*b)
max(n1*n2*n3*...*ni) --> max(ln(n1*n2*n3*...*ni)) --> max(ln(n1)+ln(n2)+...+ln(ni))
这样可以将本问题转化成一个背包大小为 n，n 个物体，物体ni大小为 i，物体ni价值为ln(i)的背包问题
        { = max{ f[i-1][j], f[i-1][j-w[i]] + v[i] }  (w[i] <= j)
f[i][j]{
        { = f[i-1][j]   (w[i] > j)
*/

int n = 0;

double f[MANN][MANN] = { 0 };
struct Obj{
    double value;
    int weight;
}obj[MANN];

double maxf(double a, double b){
    return a > b ? a : b;
}

void prework(){
    for(int i = 1; i <= n; i++){
        obj[i].weight = i;
        obj[i].value = log(i) / log(2);   
    }
}

void knaspsack(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(obj[i].weight <= j){
                f[i][j] = maxf(f[i-1][j], f[i-1][j-obj[i].weight] + obj[i].value);
            }
            else{
                f[i][j] = f[i-1][j];
            }
        }
    }
}

int main(){
    scanf("%d", &n);

    prework();
    knaspsack();

    int o[MANN] = { 0 };
    int k = 0;
    int i = n;
    int j = n;
    while(i > 0 and j > 0){
        if(f[i][j] == f[i-1][j]){
            i--;
        }
        else{
            o[++k] = i;
            j -= obj[i].weight;
            i--;
        }
    }

    unsigned long long ans = 1;
    for(int i = k; i > 0; i--){
        printf("%d ", o[i]);
        ans *= o[i];
        //printf("o[%4d] = %4d  ans = %llu\n", i, o[i], ans);
    }

    printf("\n%llu\n", ans);
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%lf ", f[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

/*

[题目描述]
一个正整数一般可以分为几个互不相同的自然数的和，如 3=1+2 3=1+2，4=1+3 4=1+3，5＝1+4=2+3 5＝1+4=2+3，6=1+5＝2+4 6=1+5＝2+4。
现在你的任务是将指定的正整数 n 分解成若干个互不相同的自然数的和，且使这些自然数的乘积最大

[输入格式]
一个正整数 n (3 <= n <= 10000)

[输出格式]
第一行是分解方案，相邻的数之间用一个空格分开，并且按由小到大的顺序
第二行是最大的乘积

[输入输出样例]
10

2 3 5
30

*/