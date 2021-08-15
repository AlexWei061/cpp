#include<bits/stdc++.h>
using namespace std;

int year, month;

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

int days(int year, int month){
    switch(month){
        case 1: case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            return 31;
            break;
        case 4 : case 6: case 9: case 11 :
            return 30;
            break;
        case 2 :
            if(isLeapYear(year)){
                return 29;
            }
            else{
                return 28;
            }
            break;
    }
}

int main(){
    scanf("%d%d", &year, &month);
    printf("%d\n", days(year, month));
    return 0;
}