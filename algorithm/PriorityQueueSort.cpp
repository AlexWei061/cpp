#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> NumList;
int num_list[1000001];

void PriorityQueueSort(int n, int num_list[]){
    for (int i = 0; i < n; i++){
        NumList.push(num_list[i]);
    }
    for (int j = 0; j < n; j++){
        num_list[j] = NumList.top();
        NumList.pop();
    }
}

int n = 0;

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&num_list[i]);
    }
    PriorityQueueSort(n, num_list);
    for (int j = 0; j < n; j++){
    	printf("%d%c",num_list[j],' ');
    
    return 0;
}
