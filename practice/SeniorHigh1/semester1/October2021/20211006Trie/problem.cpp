#include<bits/stdc++.h>
using namespace std;

#define MAXN 1001001

int trie[MAXN][30] = { 0 };
int ed[MAXN] = { 0 };
int tot = 0;
char str[100];

void buildTrie(char str[]){
	int p = 0;
	int slen = strlen(str);
	for(int i = 0; i < slen; i++){
		if(!trie[p][str[i] - 'a']){
			trie[p][str[i] - 'a'] = ++tot;
		}
		p = trie[p][str[i] - 'a'];
		ed[p]++;
	}
}

int searchTrie(char str[]){
	int p = 0;
	int slen = strlen(str);
	for(int i = 0; i < slen; i++){
		if(!trie[p][str[i] - 'a']){
			return 0;
		}
		p = trie[p][str[i] - 'a'];
	}
	return ed[p];
}

int main(){
	freopen("problem.in", "r", stdin);
	freopen("problem.out", "w", stdout);
	while(gets(str) and str[0] != '\0'){
		//printf("%s\n", str);
		buildTrie(str);
		//printf("tot = %d\n\n", tot);
	}
	while(scanf("%s", &str) != EOF){
		//printf("%s\n", str);
		printf("%d\n", searchTrie(str));
	}
	return 0;
}