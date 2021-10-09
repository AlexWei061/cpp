#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001

int q = 0;
int n = 0; int m = 0;
int order[MAXN] = { 0 };
vector<int> v[MAXN];

void dfs(int k){
	for(int i = 1; i <= m; i++){
		//printf("i = %d\n", i);
		if(m - i == 0){
			order[++k] = i;
			
			/*
			for(int j = 1; j <= k; j++){
				printf("%d ", order[j]);
			}
			puts("");
			*/
			
			int sum = 0; int ans = 0;
			for(int j = 1; j <= k; j++){
				ans += sum * order[j];
				sum += order[j];
			}
			v[n].push_back(ans);
			
			return;
		}
		order[++k] = i;
		m -= i;
		dfs(k);
		m += i; k--;
	}
}

int main(){
	//freopen("intersect.in", "r", stdin);
    //freopen("intersect.out", "w", stdout);
	scanf("%d", &q);
	
	for(int i = 1; i <= q; i++){
		int a = 0;
		scanf("%d%d", &n, &a);
		if(a == 0){
			printf("%d\n", 1);
			continue;
		}
		m = n; bool is = false;
		memset(order, 0, sizeof(order));
		if(!v[n].size()){
			dfs(0);	
		}		
		
		/*
		for(int j = 0; j < v.size(); j++){
			printf("%d ", v[j]);
		}
		puts("");
		*/
		
		for(int j = 0; j < v[n].size(); j++){
			if(v[n][j] == a){
				//printf("%d\n", 1);
				is = true; break;
			}
		}
		if(is){
			printf("%d\n", 1);
		}
		else{
			printf("%d\n", 0);
		}
		
		/*
		for(int i = 0; i < v.size(); i++){
			printf("%d ", v[i]);
		}
		puts("");
		*/	
	}
	return 0;
}
