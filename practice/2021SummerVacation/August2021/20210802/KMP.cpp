#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

/*

Knuth-Morrios-Pratt :
字符串匹配， 能在线性时间内判断字符串A[1~N]是否为字符串B[1~M]的子串，并求出字符串 A 在字符串 B 中各次出现的位置

1. 对字符串 A 进行自我匹配，生成一个 next 数组，其中next[i] 表示 A 中 "以 i 结尾的非前缀子串" 与 "A 的前缀" 能够匹配的最长长度
next[i] = max{ j }, 其中 j < i 并且 A[i-j+1 ~ i] = A[1 ~ j]
特别的，但不存在这样的 j 时 next[i] = 0
2. 对字符串 A 和 B 进行匹配，求出一个数组 f，其中 f[i] 表示 "B中以i结尾的子串" 与 "A的前缀" 能够匹配的最长长度
f[i] = max{ j }, 其中 j <= i 并且 B[i-j+1 ~ i] = A[1 ~ j]



引理 :
若 j0 是 next[i]的一个候选项, 即 j0 < i 且 A[i-j0+1 ~ i] = A[1 ~ j0] 则 小于 j0 的最大 next[i]的候选项是 next[j0]
换言之 next[i]+1 ~ j0-1 之间都不是 next[i]的候选项

证明 :
假设存在 j1 使得 next[i] < j1 < j0 且 A[i-j1+1 ~ i] = A[1 ~ j1] ---- (1)
取 A[i-j0+1 ~ i] 和 A[1 ~ j0] 的后 j1 个数, 显然这两串字符也相等 即 A[i-j1+1 ~ i] = A[j0-j1+1 ~ j0] -- (2)
联立 (1)(2) 得 A[j0-j1+1 ~ j0] = A[1 ~ j1] 也就是说 j1 是 next[j0] 的一个候选项
所以 j1 <= next[j0] 于题设相违背 故题设不成立
证毕



根据引理, 当 next[i-1]计算完毕时, 我们即可得知 next[i-1] 的候选项从大到小排列依次是 :
next[i-1], next[next[i-1]], next[next[next[i-1]]] ...
如果一个整数 j 是 next[i] 的候选项, 显然 j-1 是 next[i-1]的候选项
因此计算 next[i] 只需要把 next[i-1] + 1, next[next[i-1]] + 1, next[next[next[i-1]]] + 1 ... 作为 j 的选项即可

*/

char a[MAXN], b[MAXN];
int nxt[MAXN] = { 0 };
int   f[MAXN] = { 0 };

void KMP(char a[], char b[]){
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    /*
    计算 next[] 数组
    1. 初始化  next[1] = j = 0, 假设 next[1 ~ i-1] 已求出, 下面求解 next[i]
    2. 不断尝试扩展匹配长度 j, 如果扩展失败 (下一个字符不相等), 令 j 变成 next[j], 直到 j 为 0 (应该重新从头开始匹配)
    3. 如果能够扩展成功, 匹配长度 j 就增加 1。next[i] 的值就是 j
    */
   nxt[1] = 0;
   for(int i = 2, j = 0; i <= lena; i++){
       while(j > 0 and a[i] != a[j+1]){
           j = nxt[j];
       }
       if(a[i] == a[j+1]){
           j++;
       }
       nxt[i] = j;
   }
   //求解 f 与求解 next 的过程基本一致
   for(int i = 1, j = 0; i <= lenb; i++){
       while(j > 0 and (j == lena or b[i] != a[j+1])){
           j = nxt[j];
       }
       if(b[i] == a[j+1]){
           j++;
       }
       f[i] = j;
   }
}

int main(){
    scanf("%s%s", a + 1, b + 1);
    KMP(a, b);
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    
    for(int i = 1; i <= lena; i++){
        printf("%d ", nxt[i]);
    }
    printf("\n");
    
    for(int i = 1; i <= lenb; i++){
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
}