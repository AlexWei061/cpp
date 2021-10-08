#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
int a[MAXN] = { 0 };
priority_queue<int> q;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		q.push(-a[i]);
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", -q.top());
		q.pop();
	}
	puts("");
	return 0;
}
