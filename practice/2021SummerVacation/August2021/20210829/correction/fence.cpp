#include<bits/stdc++.h>
using namespace std;

long long sum = 0;
int n = 0, t = 0;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d", &n);
	for(int i = 1; i<= n; i++){
		scanf("%d", &t);
		q.push(t);
	}

	for(int i = 1; i < n; i++){
		int t1 = q.top();
		q.pop();
		int t2 = q.top();
		q.pop();
		t = t1 + t2;
		sum += t;
		q.push(t);
	}

	printf("%lld\n", sum);
	return 0;
}