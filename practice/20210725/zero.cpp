#include<bits/stdc++.h>
using namespace std;

//suntime complexity : O(n)
void moveZerosAlgorithm1(int numlist[], int size){            //看着代码手动模拟一边就懂了
    int zeros = 0;
    for(int i = 0 ; i < size; i++){
        if(numlist[i] != 0){
            numlist[i-zeros] = numlist[i];
        }
        else{
            zeros++;
        }
    }
    int i = size - zeros;
    while(i < size){
        numlist[i++] = 0;
    }
}

/*
快排的思想 : 把一个数组分成三段
[num, num, num, ..., num][0, 0, 0, ..., 0][unkonwn, unkonwn, ..., unkonwn]
非零数字                  0                还没看的
if(nukonwn == 0)--> 0那一段的范围就像后扩展一格
else            --> 把0那一段的第一个零和unkown交换( swap(0[0], unkonwn[0]) )
*/
//runtime complexity : O(n)
void moveZerosAlgorithm2(int numlist[], int size){
    int j = 0;
    for(int i = 0; i < size; i++){
        if(numlist[i] != 0){
            swap(numlist[i], numlist[j]);
            j++;
        }
    }
}

int main(){
    int numlist[8] = { 1, 7, 0, 2, 3, 0, 4, 8 };
    
    //moveZerosAlgorithm1(numlist, 8);
    moveZerosAlgorithm2(numlist, 8);
    
    for(int i = 0; i < 8; i++){
        printf("%d ", numlist[i]);
    }
    printf("\n");
    return 0;
}

/*
将一个数组中的0全部移动到数组末尾，其他数字顺序随意
*/