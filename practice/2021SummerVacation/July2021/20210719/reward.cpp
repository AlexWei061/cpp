#include<bits/stdc++.h>
using namespace std;

int n, m, id = 1, ans = 0;
priority_queue<int> que;

struct node{
	int day;
	int money;
}p[100005];

bool cmp(node a, node b){
	if(a.day != b.day){
		return a.day < b.day;
	}
	return a.money > b.money;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &p[i].day, &p[i].money);
	}
	
	sort(p+1, p+n+1, cmp);
	
	for(int i = 1; i <= m; i++){
		while(id <= n and p[id].day <= i){
			que.push(p[id].money);
			id++;
		}
		if(!que.empty()){
			ans += que.top();
			que.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}
