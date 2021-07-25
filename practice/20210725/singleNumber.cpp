#include<bits/stdc++.h>
using namespace std;

/*
思路:a xor a xor b = b
所以把整个数组求异或和得到的就是singlenNmber
*/

int singleNumber(int numlist[], int size){
    int k = numlist[0];
    for(int i = 1; i < size; i++){
        k ^= numlist[i];                   //求异或和
    }
    return k;
}

int main(){
    int array[] = { 5, 8, 5, 6, 7, 8, 7 };
    int ans = singleNumber(array, 7);
    printf("ans = %d\n", ans);
    return 0;
}

/*
Give an array of integers, every element appears twice except for one. Find that single one
Note : your algorithm should have linear runtime complexity. Could you implement it without using extra memory?
*/