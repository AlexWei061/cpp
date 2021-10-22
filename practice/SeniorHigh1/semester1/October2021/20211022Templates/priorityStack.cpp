#include<bits/stdc++.h>
using namespace std;
#define MAXN 3003000

// P5788

int n = 0;
int a[MAXN];
int f[MAXN];
stack<int>s;

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = n; i >= 1; i--){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		f[i]=s.empty() ? 0 : s.top();
		s.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ",f[i]);
	}
	return 0;
}