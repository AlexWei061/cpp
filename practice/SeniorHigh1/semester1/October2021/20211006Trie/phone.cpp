#include<bits/stdc++.h>
using namespace std;

#define MAXN 1010001

int t = 0;

int ed[MAXN] = { 0 };
int trie[MAXN][30] = { 0 };
int tot = 0;
char str[10010][20];

void bulidTrie(char str[]){
	int p = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - '0']){
			trie[p][str[i] - '0'] = ++tot;
		}
		p = trie[p][str[i] - '0'];
		ed[p]++;
	}
}

int searchTrie(char str[]){
	int p = 0;
	int len = strlen(str);
	for(int i = 0 ; i < len; i++){
		if(!trie[p][str[i] - '0']){
			return 0;
		}
		p = trie[p][str[i] - '0'];
	}
	return ed[p];
}

int main(){
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		memset(trie, 0, sizeof(trie));
		memset(ed, 0, sizeof(ed));
		int n = 0;
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%s", &str[j]);
			bulidTrie(str[j]);
		}
		bool a = true;
		for(int j = 0; j < n; j++){
			if(searchTrie(str[j]) != 1){
				a = false;
				break;
			}
		}
		if(a){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}