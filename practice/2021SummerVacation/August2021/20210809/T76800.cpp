#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

int trie[MAXN][11] = { 0 };
int ed[MAXN] = { 0 };
int tot = 0;
//char str[MAXN];

int t = 0;
int n = 0;
char num[5][45];

void clear(){
    memset(trie, 0, sizeof(trie));
    memset(ed, 0, sizeof(ed));
    tot = 0;
}

void insert(char str[]){
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'0']){
            trie[p][str[i]-'0'] = ++ tot;
        }
        p = trie[p][str[i]-'0'];
        ed[p]++;
    }
}

int sreach(char str[]){
    int p = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!trie[p][str[i]-'0']){
            return 0;
        }
        p = trie[p][str[i]-'0'];
    }
    return ed[p];
}

int main(){
    /*
    for(int i = 0; i < 3; i++){
        scanf("%s", num[i]);
        insert(num[i]);
    }

    for(int i = 0; i < 3; i++){
        scanf("%s", num[i]);
        printf("%d\n", sreach(num[i]));
    }
    */

    
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        clear();
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%s", num[j]);
            insert(num[j]);
        }
        bool a = true;
        for(int j = 0; j < n; j++){
            //printf("%s : %d\n", num[j], sreach(num[j]));
            if(sreach(num[j]) > 1){
                a = false;
                break;
            }
        }
        if(a == true){
            printf("%s\n", "YES");
        }
        else{
            printf("%s\n", "NO");
        }
    }
    
    return 0;
}

/*

给出一份电话号码表，如果不存在一个号码是另一个好骂的前缀，我们就称这份号码是合法的。

[输入格式]
第一行一个整数 t (1 <= t <= 40) 表示数据组数
每个数据第一行是一个整数 n (1 <= n <= 10000)，表示电话号码的数量
接下啦 n 行，每行一个电话号码，每个号码是不超过 10 位的连续数字

[输出格式]
对每组数据，如果电话号码列表合法，则输出 "YES"，不合法就输出 "NO"

2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

NO
YES

*/