#include<stdio.h>
using namespace std;

#define MAX_LEN 10000

void build_tree(int arr[], int tree[], int node, int start, int end){
    if(start == end){
         tree[node] = arr[start];                                         //or tree[node] = arr[end];
         //printf("%d ", arr[start]);
    }

    else{
        int mid = (start + end) / 2;
        //printf("mid=%d ", mid);
        int left_node  = 2 * node + 1;
        //printf("left_node=%d ", left_node);
        int right_node = 2 * node + 2;
        //printf("right_node=%d \n", right_node);

        build_tree(arr, tree, left_node,  start,   mid);
        build_tree(arr, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
	}
    
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val){
    //trun arr[idx] into val and update the tree
    if(start == end){
        arr[idx]   = val;
        tree[node] = val;
    }
    else{
        int mid = (start + end) / 2;
        int left_node  =  2 * node + 1;
        int right_node =  2 * node + 2;

        if(idx >= start and idx <= mid){
            update_tree(arr, tree, left_node,  start,   mid, idx, val);
        }
        else{
            update_tree(arr, tree, right_node, mid + 1, end, idx, val);
        }
        tree[node] = tree[left_node] + tree[right_node];

    }
}

int query_tree(int arr[], int tree[], int node, int start, int end, int left, int right){
    //sum of arr[i] i blongs to[left, right]
    //printf("start=%d ", start);
    //printf("end=%d\n", end);
    if(right < start or left > end){
        return 0;
    }
    else if(start == end){
        return tree[node];
    }
    else if(left <= start and right >= end){
        return tree[node];
    }
    else{
        int mid = (start + end) / 2;
        int left_node =  2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left  = query_tree(arr, tree, left_node,  start,   mid, left, right);
        int sum_right = query_tree(arr, tree, right_node, mid + 1, end, left, right);
        return sum_left + sum_right;
    }
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = 6;
    int tree[MAX_LEN] = { 0 };

    int idx = 4;
    int val = 6;

    int left =  2;
    int right = 5;

    build_tree(arr, tree, 0, 0, size - 1);

    update_tree(arr, tree, 0, 0, size - 1, idx, val);

    for(int i = 0; i < 15; i++){
        printf("tree[%d] = %d\n", i, tree[i]);
    }

    int s = query_tree(arr, tree, 0, 0, size - 1, left, right);

    printf("%d\n", s);

    return 0;
}
