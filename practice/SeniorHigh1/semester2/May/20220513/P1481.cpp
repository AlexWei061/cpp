#include<bits/stdc++.h>
using namespace std;
#define MAXN 2020

int n = 0; int tot = 0;
char s[MAXN][MAXN];
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
	int p = 0; int ans = 0; int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!trie[p][str[i] - 'a']) return 0;
		p = trie[p][str[i] - 'a'];
		ans += ed[p];
	}
	return ans;
}

int main(){
	scanf("%d", &n); int ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%s", &s[i]); build(s[i]);
	}
	for(int i = 1; i <= n; i++) ans = max(ans, query(s[i]));
	cout << ans << '\n';
//	for(int i = 1; i <= n; i++){
//		scanf("%s", &s); build(s);
//	}
//	cout << query(s);
	return 0;
}

/*
5
i
int
integer
intern
internet
*/