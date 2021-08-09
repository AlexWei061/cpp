#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n = 10;
int  arr[MAXN] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int tree[MAXN] = { 0 };

int lowbit(int x){                    // x 的二进制末尾 0 的数量
    return x & (-x);
}

void update(int i, int x){            // arr[i] += x
    while(i <= n){
        tree[i] += x;
        i += lowbit(i);
    }
}

int query(int m){                     // return \sum_{i=1}^{m}arr[i]
    int sum = 0;
    while(m > 0){
        sum += tree[m];
        m -= lowbit(m);
    }
    return sum;
}

int main(){
    update(1, 1);
    update(2, 2);
    update(3, 3);
    update(4, 4);
    update(5, 5);
    update(6, 6);
    update(7, 7);
    update(8, 8);
    update(9, 9);
    update(10, 10);

    printf("%d\n", query(10));
    return 0;
}
