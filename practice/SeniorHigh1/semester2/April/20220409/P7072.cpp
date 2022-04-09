#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 100100

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int w = 0;
priority_queue<int> bq;                                          // 大跟堆 
priority_queue<int, vector<int>, greater<int>> sq;               // 小根堆 

void adjust(int rank){
	while(sq.size() < rank) { sq.push(bq.top()); bq.pop(); }
	while(sq.size() > rank) { bq.push(sq.top()); sq.pop(); }
}

int main(){
	n = in; w = in; bq.push(0);
	for(int i = 1; i <= n; i++){
		int a = in; int r = max(1, i * w / 100);
		if(a > bq.top()) sq.push(a);
		else bq.push(a);adjust(r);
		cout << sq.top() << ' ';
	}
	puts("");
	return 0;
}