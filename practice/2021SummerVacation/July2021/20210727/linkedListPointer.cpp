#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *prev, *next;
};
Node *head, *tail;

void initailize(){                             //新建链表
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

void insert(Node *p, int val){                 //在p后添加一个数值为val的新节点
    Node *newNode = new Node;
    newNode->value = val;
    p->next->prev = newNode;
    newNode->next = p->next;
    p->next = newNode;
    newNode->prev = p;
}

void remove(Node *p){                          //删除p
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

void recycle(){                                //删除整个链表
    while(head != tail){
        head = head->next;
        delete head->prev;
    }
    delete tail;
}

int main(){

    return 0;
}