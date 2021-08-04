#include<bits/stdc++.h>
using namespace std;

/*

求解 a^x ≡ b (mod p)
设 x = t * i - j  其中  (t = ceil(sqrt(t)))  0 <= j <= t-1
方程变形为 a^(t*i - j) ≡ b (mod p) 即 (a^t)^i ≡ b * a^j (mod p                                                                                                                                                                                                                                          ) 

对于所有 0 <= j <= t-1 计算 b * a^j mod p 插入一个 Hash 表
对于所有 0 <= i <= t 计算 (a^t)^i mod p 在 Hash 表中查找是否有 j 与其对应并更新答案

*/

int power(int a, int b, int p){                      //快速幂取模
    long long ans = 1;
    a %= p;
    while(b > 0){
        if(b & 1){
            ans = (long long)ans * a % p;
        }
        b >>= 1;
        a = (long long)a * a % p;
    }
    return ans;
}

int babyStepGaintStep(int a, int b, int p){
    map<int, int> hash;
    hash.clear();
    b %= p;
    int t = (int)sqrt(p) + 1;                        //ceil(sqrt(p))
    for(int j = 0; j < t; j++){
        int value = b * power(a, j, p) % p;
        hash[value] = j;
    }
    a = power(a, t, p);                              //a^t
    if(a == 0){
        return b == 0 ? 1 : -1;
    }
    for(int i = 0; i <= t; i++){
        int value = power(a, i, p);                  //(a^t)^i
        int j = hash.find(value) == hash.end() ? -1 : hash[value];
        if(j >= 0 and i * t - j >= 0){
            return i * t - j;
        }
        return -1;
    }
}

int main(){
    
    return 0;
}