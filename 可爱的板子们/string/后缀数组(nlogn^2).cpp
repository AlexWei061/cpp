#include<bits/stdc++.h>
using namespace std;
#define mod 233
#define ull unsigned long long
#define MAXN 1001000

int n = 0;
ull base[MAXN] = { 0 };                                                   // base[i] = mod ^ i
ull Hash[MAXN] = { 0 };                                                   // 哈希值 
char str[MAXN];
int SA[MAXN] = { 0 };

inline ull get(int l, int r){                                             // O(1) 求子串哈希 
	return Hash[r] - Hash[l - 1] * base[r - l + 1];
}

bool comp(int x, int y){                                                  // 手写比较函数 
    int l = -1, r = min(n - x, n - y);                                    // 在两个后缀的长度之内二分 
    while(l < r){                                                         // 二分 
        int mid = (l + r + 1) >> 1;
        if(get(x, x + mid) == get(y, y + mid)) l = mid;                   // 前半部分相同 
        else r = mid - 1;                                                 // 不同 
    }
    if(l > min(n - x, n - y)) return x > y;                               // 左端点超过了右端点 说明短的是长的的子串 那么按照字符串长度来排名 
    else return str[x + l + 1] < str[y + l + 1];                          // 没超过 就按照第一个不同的地方的大小比较 
}

int main(){
    scanf("%s", str + 1);
    n = strlen(str + 1);
    base[0] = 1;
    for(int i=1;i<=n;i++){
        base[i] = base[i - 1] * mod;
        Hash[i] = Hash[i - 1] * mod + str[i];
        SA[i] = i;
    }
    stable_sort(SA + 1, SA + n + 1, comp);
    for(int i = 1; i <= n; i++) printf("%d ", SA[i]);
    return 0;
}
