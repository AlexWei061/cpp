#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

struct sd{
    int flag, data;
};

bool operator < (const sd x, const sd y){
    return x.data < y.data;
}

priority_queue<sd> list;
int num = 5;

int main(){
    for(int i = 1; i <= num; i++){
        sd x;
        scanf("%d", &x.data);
        x.flag = i;
        list.push(x);
    }
    printf("%d\n", list.top().flag);
    return 0;
}
