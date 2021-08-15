#include<bits/stdc++.h>
using namespace std;

#define MAXN  100010

//字典树 Trie

int trie[MAXN][26];                    // 假设字符串由小写字母组成
int tot = 1;
bool eend[MAXN];

void insert(char* str){
    int len = strlen(str);
    int p = 1;
    for(int i = 0; i < len; i++){
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0){
            trie[p][ch] = ++tot;
        }
        p = trie[p][ch];
    }
    eend[p] = true;
}

bool search(char* str){
    int len = strlen(str);
    int p = 1;
    for(int i = 0; i < len; i++){
        int ch = str[i] - 'a';
        p = trie[p][ch];
        if(p == 0){
            return false;
        }
    }
    return eend[p];
}

int main(){
    /*
    insert("cab");
    insert("cos");
    insert("cat");
    insert("car");
    insert("cate");
    insert("rain");

    printf("is cab in list = %d\n", search("cab"));
    printf("is cos in list = %d\n", search("cos"));
    printf("is car in list = %d\n", search("car"));
    printf("is cat in list = %d\n", search("cat"));
    printf("is cate in list = %d\n", search("cate"));
    printf("is rain in list = %d\n", search("rain"));

    printf("is soc in list = %d\n", search("soc"));
    printf("is ada in list = %d\n", search("ada"));

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 26; j++){
            printf("%-3d ", trie[i][j]);
        }
        printf("\n");
    }
    */
   
    return 0;
}