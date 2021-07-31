#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 100000

/*
树状数组两个操作:
query()  --区间求和 O(log2n)
update() --该数字   O(log2n)

树状数组存储方式:
          0  1  2  3  4  5
arr[] = { 1, 3, 5, 7, 9, 11 }
                            0(下标)
                          ([0-5]:36)                                              #[m-n]表示下标从m到n的区间和
                        /           \
                       /             \
                     1                   2
                ([0-2]:9)            ([3-5]:27) 
                /       \           /          \
               /         \         /            \
              3           4       5              6
          ([0-1]:4)   ([2]:5)  ([3-4]:16)    ([5]:11)
          /      \            /        \            
         /        \          /          \
       7           8 (9 10) 11          12      (13 14)
   ([0]:1)      ([1]:3)   ([3]:7)     ([4]:9)

           0   1  2   3  4  5   6   7  8  9  10 11 12 13 14
tree[] = { 36, 9, 27, 4, 5, 16, 11, 1, 3, X, X, 7, 9, x, x }
*/

//一下代码中tree的下标都加上"node"

void bulidTree(int arr[], int tree[], int node, int L, int R){                    //建立树状数组     
    if(L == R){
        tree[node] = arr[L];
    }
    else{
        int mid = (L + R) / 2;
        int  leftNode = node * 2 + 1;
        int rightNode = node * 2 + 2;
        bulidTree(arr, tree, leftNode, L, mid);
        bulidTree(arr, tree, rightNode, mid+1, R);
        tree[node] = tree[leftNode] + tree[rightNode];
    }
}

void update(int arr[], int tree[], int node, int L, int R, int index, int value){ //arr[index] = value
    if(L == R){
        arr[index] = value;
        tree[node] = value;
    }
    else{
        int mid = (L + R) / 2;
        int  leftNode = node * 2 + 1;
        int rightNode = node * 2 + 2;
        if(index >= L and index <= mid){                                          //index在在分支上
            update(arr, tree, leftNode, L, mid, index, value);                    //修改做分支
        }
        else{                                                                     //index在右分支上
            update(arr, tree, rightNode, mid+1, R, index, value);                 //修改右分支
        }
        tree[node] = tree[leftNode] + tree[rightNode];
        }
}

int query(int arr[], int tree[], int node, int L, int R, int leftBorder, int rightBorder){
    if(leftBorder > R or rightBorder < L){
        return 0;
    }
    else if((L == R) or (leftBorder <= L and R <= rightBorder)){
        return tree[node];
    }
    else{
        int mid = (L + R) / 2;
        int  leftNode = node * 2 + 1;
        int rightNode = node * 2 + 2;
        int  sumLeft = query(arr, tree, leftNode, L, mid, leftBorder, rightBorder);
        int sumRight = query(arr, tree, rightNode, mid+1, R, leftBorder, rightBorder);
        int sum = sumLeft + sumRight;
        return sum;
    }
}

int main(){
    int arr[6] = { 1, 3, 5, 7, 9, 11 };
    int size = 6;
    int tree[MAX_LEN] = { 0 };

    bulidTree(arr, tree, 0, 0, 5);                                               //从0到5(arr下标)建立根节点为0(tree下标)的线段树

    for(int i = 0; i < 15; i++){
        printf("tree[%d] = %d\n", i, tree[i]);
    }
    printf("\n");

    printf("arr[4] = 6\n");
    update(arr, tree, 0, 0, 5, 4, 6);

    for(int i = 0; i < 15; i++){
        printf("tree[%d] = %d\n", i, tree[i]);
    }
    printf("\n");

    int sum = query(arr, tree, 0, 0, 5, 2, 5);
    printf("sum from 2 to 5 = %d\n", sum);
    return 0;
}
