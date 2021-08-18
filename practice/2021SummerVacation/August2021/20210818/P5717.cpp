#include<bits/stdc++.h>
using namespace std;

int a, b, c;

void ssort(int &a, int &b, int &c){
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
    ssort(a, b, c);

    if(a + b <= c){
        printf("Not triangle\n");
        return 0;
    }

    if((c * c) == (a * a) + (b * b)){
        printf("Right triangle\n");
    }
    else if((c * c) <= (a * a) + (b * b)){
        printf("Acute triangle\n");
    }
    else if((c * c) >= (a * a) + (b * b)){
        printf("Obtuse triangle\n");
    }

    if(a == b or a == c or b == c){
        printf("Isosceles triangle\n");
    }

    if(a == b and b == c){
        printf("Equilateral triangle\n");
    }

    return 0;
}

/*

给出三条线段 a,b,c 的长度，均是不大于 10000 的整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

*/