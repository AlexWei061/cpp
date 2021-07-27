#include<bits/stdc++.h>
using namespace std;

void heapify(int tree[], int n, int i){                 //对一颗有n个结点的树的第i个节点调整
    if(i >= n){
        return;
    }
    int c1 = 2 * i + 1;                                 //两个子节点的下标
    int c2 = 2 * i + 2;
    //找出三个节点中的最大值
    int mmax = i;
    if((c1 < n )/*不越界*/ and tree[c1] > tree[mmax]){
        mmax = c1;
    } 
    if((c2 < n)/*不越界*/ and tree[c2] > tree[mmax]){
        mmax = c2;
    }
    //交换并对下面的max位置继续heapify
    if(mmax != i){
        swap(tree[mmax], tree[i]);
        heapify(tree, n, mmax);
    }
}

void bulidHeap(int tree[], int n){                      //构建堆
    int last_node = n-1;                                //树上的最后一个节点
    int parent = (last_node-1) / 2;                     //最后一个需要heapify的节点
    //从最后一个节点开始倒着回去把所有的节点做一遍heapify
    for(int i = parent; i >= 0; i--){
        heapify(tree, n, i);
    }
}

void heapSort(int tree[], int n){
    bulidHeap(tree, n);                                 //创建一个堆
    for(int i = n-1; i >= 0; i--){                      //排序每个数
        swap(tree[0], tree[i]);                         //堆顶和最后一个属互换
        heapify(tree, i, 0);                            //去掉最后的节点并进行heapify保证还是一个堆
    }
}

int main(){
    int tree[] = { 2, 5, 3, 1, 10, 4 };
    int n = 6;
    heapSort(tree, n);
    for(int i = 0; i < n; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
    return 0;
}