#include<bits/stdc++.h>
using namespace std;

int n = 0;
priority_queue<int> ene;                    // 默认大根堆

int merge(){
    int ans = 0;
	for(int i = 1; i < n; i++){             // n 堆果子需要合并 n-1 次
		int temp = ene.top();               // temp 是个负数
		ene.pop();
		temp += ene.top();
		ene.pop();
		ans -= temp;
		ene.push(temp);
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int temp = 0;
		scanf("%d", &temp);
		ene.push(-temp);                    // push(-temp) 表示生成小根堆 (所有值都是负数)
 	}

 	printf("%d\n", merge());
	return 0;
}