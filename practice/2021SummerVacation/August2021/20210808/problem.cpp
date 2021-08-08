#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int trie[MAXN][26];
int   ed[MAXN];
int    tot = 0;
char   str[15];

void insert(char str[]){
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'a']){
            trie[p][str[i]-'a'] = ++tot;
        }
        p = trie[p][str[i]-'a'];
        ed[p]++;
    }
}

int search(char str[]){
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'a']){
            return 0;
        }
        p = trie[p][str[i]-'a'];
    }
    return ed[p];
}

int main(){
    while(gets(str), str[0] != '\0'){
        insert(str);
    }
    while(scanf("%s", str) != EOF){
        printf("%d\n", search(str));
    }
    return 0;
}

/*

老师交给 Lgnatius 很多单词 (只有小写字母组成，不会有重复的单词出现), 现在老师要求他统计出以某个单词作为前缀的单词的数量。

[输入格式]
第一部分时一张单词表，每行一个单词，单词长度不超过 10 
接下来是一个空行表示第一部分结束
接下来是一连串提问

*/