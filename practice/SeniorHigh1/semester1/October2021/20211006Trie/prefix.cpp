#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001001

int n = 0; int m = 0;
int ed[MAXN] = { 0 };
int trie[MAXN][30] = { 0 };
int tot = 0;
char str[100];

void bulidTrie(char str[]){
	int p = 0;
	int slen = strlen(str);
	for(int i = 0; i < slen; i++){
		if(!trie[p][str[i] - 'a']){
			trie[p][str[i] - 'a'] = ++tot;
		}
		p = trie[p][str[i] - 'a'];
	}
	ed[p]++;
}

int searchTrie(char str[]){
	int p = 0;
	int slen = strlen(str);
	int ans = 0;
	for(int i = 0 ; i < slen; i++){
		if(!trie[p][str[i] - 'a']){
			return ans;
		}
		p = trie[p][str[i] - 'a'];
		ans += ed[p];
	}
	return ans;
}
	
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", &str);
		bulidTrie(str);
	}

	for(int i = 1; i <= m; i++){
		scanf("%s", &str);
		printf("%d\n", searchTrie(str));
	}
	return 0;
}