#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void sort(int &a, int &b, int &c){
    if(a > b){
        swap(a, b);
    }
    if(a > c){
        swap(a, c);
    }
    if(b > c){
        swap(b, c);
    }
}

int main(){
    scanf("%d%d%d", &a, &b, &c);
    //int temp = findMax(a, b, c);
    sort(a, b, c);
    //printf("%d %d %d\n", a, b, c);
    int ggcd = gcd(a, c);
    printf("%d/%d\n", a/ggcd, c/ggcd);
    return 0;
}

/*

输入一组勾股数, 用分数的格式输出较小的的锐角的正弦值

3 4 5

3/5

*/