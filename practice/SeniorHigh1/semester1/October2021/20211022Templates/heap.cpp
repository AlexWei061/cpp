#include<bits/stdc++.h>
using namespace std;

// P3378 

int n = 0;
priority_queue<int> q;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int op = 0;
		scanf("%d", &op);
		if(op == 1){
			int x = 0;
			scanf("%d", &x);
			q.push(-x);
		}
		else if(op == 2){
			printf("%d\n", -q.top());
		}
		else if(op == 3){
			q.pop();
		}
	}
	return 0;
}