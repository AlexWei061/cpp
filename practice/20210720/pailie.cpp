#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a[50] = { 0 };
bool is_used[50];

void print(){
	for(int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void dfs(int depth){
	if(depth == n){
		print();
		return;
	}
	for(int i = 1; i <= n; i++){
		if(is_used[i] == false){
			is_used[i] = true;
			a[depth+1] = i;
			dfs(depth+1);
			is_used[i] = false;
		}
	}
}

int main(){
	freopen("pailie.out", "w", stdout);
	scanf("%d", &n);
	//printf("%d", n);
	dfs(0);
	return 0;
}
