#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n = 0;
int m = 0;

int trie[MAXN][26] = { 0 };
int ed[MAXN] = { 0 };
int tot = 0;
char str[MAXN];

void insert(char str[]){
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'a']){
            trie[p][str[i]-'a'] = ++tot;
        }
        p = trie[p][str[i]-'a'];
    }
    ed[p]++;
}

int search(char str[]){
    int ans = 0;
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'a']){
            return ans;
        }
        p = trie[p][str[i]-'a'];
        ans += ed[p];
    }
    return ans;
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%s", str);
        insert(str);
    }

    for(int i = 0; i < m; i++){
        scanf("%s", str);
        printf("%d\n", search(str));
    }
    return 0;
}