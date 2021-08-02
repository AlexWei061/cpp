#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000010
#define P 131

/*

String Hash :
O(n) 预处理 Hash 值 O(1) 查询 Hash 值
以下字符串 Hash 函数可以把一个任意长的字符映射成一个非负整数, 并且其冲突概率几乎为零
取一固定值 P , 把字符串看作 P 进制数, 并分配一个大于 0 的数值, 代表每种字符。一般来说, 我们分配的数值都远小于 P。
例如, 对于小写字母构成的字符串, 可以令 a = 1, b = 2, ..., z = 26。取一固定值 M, 求出该 P 进制数对 M 的余数, 作为该字符串的 Hash 值
一般来说, 我们取 P = 131 或 P = 13331, 此时 Hash 值产生冲突的概率极低, 只要 Hash 值相同, 我们就可以认为原字符串时相等的
通常我们取 M = 2^64 即直接用 unsigned long long 类型存储这个 Hash 值, 计算时不需要处理溢出问题, 溢出时就相当于自动对 2^64 取余 
(这样可以避免低效的模运算) 

如果把字符串 S 的 Hash 值计为 H(S), 在 S 后面添加一个字符 c 计为 S + c 那么 H(S + c) = (H(S) * P + value[c]) mod M 
在 S 后添加字符串 T 则 H(T) = ( H(S + T) - H(S) * P^(length(T)) ) mod M
(value[c] 表示 c 选定的数值, *P 表示 P 进制下的左移操作)

eg :
S = "abc" , c = 'd' , T = "xyz"
H(S) = 1 * P^2 + 2 * P + 3
H(S + c) = 1 * P^3 + 2 * P^2 + 3 * P + 4 = H(S) * P + 4

S + T 表示的 P 进制数 : 1 2 3 24 25 26
H(S + T) = 1 * P^5 + 2 * P^4 + 3 * P^3 + 24 * P^2 + 25 * P + 26
S 在 P 进制下左移 length(T) 位 : 1 2 3 0 0 0
二者相减就是 T 的 P 进制数 24 25 26
H(T) = H(S + T) - (1 * P^2 + 2 * P + 3) * P^3 = 24 * P^2 + 25 * P + 26

*/

char s[MAXN];
unsigned long long f[MAXN] = { 0 };
unsigned long long p[MAXN] = { 0 };

unsigned long long StringHash(char s[]){
    int len = strlen(s + 1);
    p[0] = 1;                                             //P^0 = 1
    for(int i = 1; i <= len; i++){
        f[i] = f[i-1] * P + (s[i] - 'a' + 1);             //Hash(S + c) = (Hash(S) * P + value[c]) mod M (value[c] = c - 'a' + 1)
        p[i] = p[i-1] * P;                                //P^i
    }
    return f[len];
}

int main(){
    scanf("%s", s + 1);

    unsigned long long hashS = StringHash(s);
    printf("%llu", hashS);
    return 0;
}

/*

例题 : 
给定字符串 S, 求它的最大回文子串

*/