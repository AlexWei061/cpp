#include <bits/stdc++.h>
using namespace std;
 
typedef struct node_s {
    int now_sec;
    struct node_s* next;
    struct node_s* prev;
} node_t;


node_t* head = NULL;

void insert(node_t* node) {
	//重置next/prev指针为空，以防万一调用者忘记置空 
	node->next = NULL;
	node->prev = NULL;
	 
    if (head == NULL) {
        head = node;
        return; // head == NULL; and return NULL, means insert head = node;
    }
    
    
    node_t* cur = head;
    do {
        if (cur->now_sec >= node->now_sec) {
        	//数据操作 
            cur->now_sec -= node->now_sec;
            
            if (cur->prev != NULL) { //插入到链表两个节点中间 
                cur = cur->prev; 
                
			    node->next = cur->next;
			    cur->next = node;
			    node->next->prev = node;
			    node->prev = cur;
            }
            else {//插入到链表头部 
                head = node;
                node->next = cur;
                cur->prev = node;
            }
            
            break;
        }
        if (cur->next == NULL) {//插入到链表尾部 
        	//数据操作
            node->now_sec -= cur->now_sec;
            
            cur->next = node;
            node->prev = cur;
            break; 
        }
        else {
        	//继续寻找下一个节点 
            node->now_sec -= cur->now_sec;
            cur = cur->next;
        }
    } while (true);
}


int time(int m, int n, int w[]) {
    int have_water = 0;
    int total_sec = 0;
    int init_num = n >= m ? m : n; //最开始可以同时开始接水的人数 

	//安排第一轮要接水的人 
    for (int i = 0; i<init_num; i++) {
        node_t* node = new node_t;
        memset(node, 0, sizeof(node_t));
        node->now_sec = w[i];
        insert(node);
    }

    have_water = init_num;

    //循环操作链表头部节点，直到链表为空 
    while (head != NULL) {
        node_t* timeout_node = head;
        total_sec += timeout_node->now_sec;
        
        //将头部节点从链表中删除 
        if (head->next != NULL) {
            head->next->prev = NULL;
        }
        head = head->next;
 
        if (have_water<n) { //如何还有人还在等待接水 
        	//安排下一个人接水 
            timeout_node->now_sec = w[have_water];
            have_water++;
            timeout_node->next = NULL;
        	timeout_node->prev = NULL;
            insert(timeout_node); //重新插入链表 
        }
        else { //没有人接水了，删除该水龙头 
            delete timeout_node;
        }
    }

    return total_sec;
}


int main() {
	int m = 0;                             //水龙头数量
	int n = 0;                             //接水人数
	cin >> n >> m;
	int * w = new int[n];                //接水水量list
	for (int i = 0;i<n;i++) {
		cin >> w[i];
	}
	
	cout << time(m, n, w) << endl;
	delete w;
    return 0;
}
