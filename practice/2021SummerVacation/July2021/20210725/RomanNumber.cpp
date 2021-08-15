#include<bits/stdc++.h>
using namespace std;

#define N 7

/*
I : 1
V : 5
X : 10
L : 50
C : 100
D : 500
M : 1000
1.几个相同大小的数并排在一起表示加发
2.在罗马数字中最大的数的左边的数减法，在右边的表示加法
eg : IL-->49, LI-->51
1 I     6  VI    11 XI
2 II    7  VII   12 XII
3 III   8  VIII  13 XIII
4 IV    9  IX    14 XIV
5 V     10 X     15 XV
*/

char digits[N] = { 'I', 'V', 'X', 'L',  'C', 'D',  'M' };
int  values[N] = {  1 ,  5 ,  10,  50,  100, 500, 1000 };

int digitsToValues(char ch){
    for(int i = 0; i < N; i++){
        if(digits[i] == ch){
            return values[i];
        }
    }
    return 0;
}

int findMaxIndex(char str[], int L, int R){
    int mmax = digitsToValues(str[L]);
    int maxIndex = L;
    for(int i = L; i <= R; i++){
        int num = digitsToValues(str[i]);
        if(num > mmax){
            mmax = num;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int RomanToArabic(char str[], int L, int R){
    if(L == R){
        return digitsToValues(str[L]);
    }
    else if(L > R){
        return 0;
    }
    else{
        int maxIndex = findMaxIndex(str, L, R);
        int mmax = digitsToValues(str[maxIndex]);
        int left  = RomanToArabic(str, L, maxIndex-1);
        int right = RomanToArabic(str, maxIndex+1, R);
        return mmax - left + right; 
    }
}

int main(){
    char RomanNumber[] = "MCMLIV";
    int ans = RomanToArabic(RomanNumber, 0, 5);
    printf("ans = %d\n", ans);
    return 0;
}

/*
turn Roman numerals into Arabic numerals
*/