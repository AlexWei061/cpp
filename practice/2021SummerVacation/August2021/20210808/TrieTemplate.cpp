#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define SIZE 26

int trie[MAXN][SIZE];                             // 节点 i 的第 j 个节点的编号 
int   ed[MAXN];                                   // trie[p] : trie树中从根节点到 p 位置的单词数。  
int  tot;                                         // 节点编号

void insert(char str[]){
    int p = 0;                                    // 从根节点开始
    for(int i = 0; i < strlen(str); i++){         // 枚举 S 中的每个字符
        if(!trie[p][str[i] - 'a']){               // 如果 str[i] 不存在
            trie[p][str[i] - 'a'] = ++tot;        // 插入str[i],节点编号 ++tot
        }
        p = trie[p][str[i] - 'a'];                // 指针移动到下一个位置
        ed[p]++;                                  // 累加从根节点到 p 位置的单词的数量
    }
}

int search(char str[]){
    int p = 0;                                    // 从根节点开始
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i] - 'a']){
            return 0;                             // 该单词不存在
        }
        p = trie[p][str[i] - 'a'];
    }
    return ed[p];                                 // 返回该单词的数量
}

int main(){
    char str[MAXN];                               // 需要插入或需要检索的字符串
    
    insert("cab");
    insert("cos");
    insert("car");
    insert("cat");
    insert("cate");
    insert("rain");
    insert("cos");

    printf("%d\n", search("abc"));
    printf("%d\n", search("cos"));
    printf("%d\n", search("rain"));

    return 0;
}