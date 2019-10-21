#include<iostream>
#include<queue>
using namespace std;

void PriorityQueueSort(int n, int num_list[]){
    priority_queue<int> NumList;
    for (int i = 0; i < n; i++){
        NumList.push(num_list[i]);
    }
    for (int j = 0; j < n; j++){
        printf("%d%c",NumList.top(),' ');
        NumList.pop();
    }
}

int num_list[1000001];
int n = 0;

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&num_list[i]);
    }
    PriorityQueueSort(n, num_list);
    return 0;
}