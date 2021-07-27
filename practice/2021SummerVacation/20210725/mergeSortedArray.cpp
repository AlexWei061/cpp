#include<bits/stdc++.h>
using namespace std;

void merge(int num1[], int num2[], int m, int n){
    int array[100001] = { 0 };
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m and j < n){
        if(num1[i] < num2[j]){
            array[k++] = num1[i++];
        }
        else{
            array[k++] = num2[j++];
        }
    }

    while(i < m){
        array[k++] = num1[i++];
    }
    while(j < n){
        array[k++] = num2[j++];
    }
    for(i = 0; i < k; i++){
        num1[i] = array[i];
    }
}

void printArray(int numlist[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", numlist[i]);
    }
    printf("\n");
}

int main(){
    int num1[100] = {1, 3, 4, 5, 8, 9};
    int num2[5] = { 5, 6, 7, 10, 11 };
    
    merge(num1, num2, 6, 5);
    printArray(num1, 11);
    return 0;
}

/*
Give two sorted integer arrays num1 and num2, merge num2 into num1 an one sorted array.
you may assume that num1 has enough space (size that is greater or eqaul to n+m)to hold additional element from num2.
The number of elements in initialized in num1 and num2 are m and n respectively
*/