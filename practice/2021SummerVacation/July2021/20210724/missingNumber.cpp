#include<bits/stdc++.h>
using namespace std;

/*
思路：
将1~n求和sum(1~n)=n(n+1)/2
在减去给出的数组的和就是所要求的答案
*/

int missingNum(int numlist[], int size){
    int sum = size * (size+1) / 2;
    int temp = 0;
    for(int i = 0; i < size; i++){
        temp += numlist[i];
    }
    return sum - temp;
}

int main(){
    int array[] = {0, 1, 3};
    int len = sizeof(array)/sizeof(int);
    printf("%d\n", len);
    printf("ans = %d\n", missingNum(array, len));
    return 0;
}

/*
Given an array containing n distinct number taken from 0, 1, 3..., n. Find the one that is missing from the array
eg:[0, 1, 3]
return 2
Note : your algorithm should run in linear runtime complexity.Cloud you implement it using only constant extra space complexity? 
*/