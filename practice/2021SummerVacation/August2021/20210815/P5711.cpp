#include<bits/stdc++.h>
using namespace std;

int year = 0;

bool isLeapYear(int year){
    if(year % 100 == 0){
        if((year / 100) % 4 == 0){
            return true;
        }
    }
    else if(year % 4 == 0){
        return true;
    }
    return false;
}

int main(){
    scanf("%d", &year);
    printf("%d\n", isLeapYear(year));
    return 0;
}

// 判断是不是闰年