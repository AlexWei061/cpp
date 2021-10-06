#include<bits/stdc++.h>
using namespace std;

#define MAXN 10001000

int n = 0;
int ans = -1;

int trie[MAXN][10] = { 0 };
int tot = 0;

void insert(int x){
	int p = 0;
	for(int i = 30; i >= 0; i--){
		int t = (x >> i) & 1;
		if(!trie[p][t]){
			trie[p][t] = ++tot;
		}
		p = trie[p][t];
	}
}

int search(int x){
	int p = 0;
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		int t = (x >> i) & 1;
		if(trie[p][t^1]){
			ans += (1 << i);
			p = trie[p][t^1];
		}
		else{
			p = trie[p][t];
		}
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a = 0;
		scanf("%d", &a);
		insert(a);
		ans = max(ans, search(a));
	}
	printf("%d\n", ans);
	return 0;
}