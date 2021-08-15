#include<bits/stdc++.h>
using namespace std;

int a, b, c;

void comp(int a, int b, int c){
    if(a>b){
        swap(a, b);
    }
    if(b > c){
        swap(b, c);
    }
    if(a > b){
        swap(a, b);
    }
    printf("%d %d %d\n", a, b, c);
}

int main(){
    scanf("%d%d%d", &a, &b, &c);
    comp(a, b, c);
    return 0;
}