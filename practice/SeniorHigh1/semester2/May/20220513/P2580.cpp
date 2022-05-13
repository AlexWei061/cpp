#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500

int n = 0; int m = 0;
char s[MAXN];
int tot = 0;
int trie[MAXN][30] = { 0 };
int ed[MAXN] = { 0 };

void build(char str[]){
	int p = 0; int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - 'a'])
			trie[p][str[i] - 'a'] = ++tot;
		p = trie[p][str[i] - 'a'];
	}
	ed[p]++;
}

int query(char str[]){
	int p = 0; int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - 'a']) return 0;
		p = trie[p][str[i] - 'a'];
	}
	int ans= ed[p]; ed[p] = -1; return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", &s); build(s);
	} scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%s", &s); int k = query(s);
		if(k == 0) cout << "WRONG\n";
		else if(k == -1) cout << "REPEAT\n";
		else cout << "OK\n"; 
	}
	return 0;
}