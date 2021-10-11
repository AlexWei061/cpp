#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int tot = 0;
char str[MAXN];
int trie[MAXN][30] = { 0 };
int ed[MAXN] = { 0 };

void buildTrie(char str[]){
	int p = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - 'a']){
			trie[p][str[i] - 'a'] = ++tot;
		}
		p = trie[p][str[i] - 'a'];
	}
	ed[p]++;
}

int query(char str[]){
	int p = 0;
	int ans = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - 'a']){
			return 0;
		}
		p = trie[p][str[i] - 'a'];
		ans += ed[p];
	}
	return ans;
}

int main(){
	scanf("%s", str);
	return 0;
}
