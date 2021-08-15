#include<bits/stdc++.h>
using namespace std;

#define SIZE 10001

struct Node{
    int value;
    int prev, next;
}node[SIZE];
int head, tail, tot;                           //头尾指针和总数

void initailize(){                             //新建链表
    tot = 2;
    head = 1, tail = 2;
    node[head].next = tail;
    node[tail].prev = head;
}

void insert(int p, int val){                   //在p后添加一个数值为val的新节点
    int newNode = ++tot;                       //在链表尾部添加一个节点
    node[newNode].value = val;
    node[node[p].next].prev = newNode;
    node[newNode].next = node[p].next;
    node[p].next = newNode;
    node[newNode].prev = p;
}

void remove(int p){                            //删除p
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}

void clear(){                                  //删除整个链表
    memset(node, 0, sizeof(node));
    head = tail = tot = 0;
}

int main(){

    return 0;
}