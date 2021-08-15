#include<bits/stdc++.h>
using namespace std;

int majorityElement(int numlist[], int size){
    int stack[500];
    int top = -1;

    for(int i = 0; i < size; i++){
        if(top == -1){                          //栈空-->入栈
            stack[++top] = numlist[i];
        }
        else if(stack[top] == numlist[i]){      //栈顶==元素 --> r入栈
            stack[++top] = numlist[i];
        }
        else{                                   //出栈
            top--;
        }
    }
    return stack[0];
}

int main(){
    int num[] = {1, 1, 1, 1, 1, 2, 3, 4, 5};
    int ans = majorityElement(num, sizeof(num)/sizeof(int));
    printf("%d\n", ans);
    return 0;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than abs(n/2) times.
you may assume that the array is non-empty and the majority element always exist in the array 
*/