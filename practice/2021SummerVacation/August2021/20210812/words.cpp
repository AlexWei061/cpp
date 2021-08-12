#include<bits/stdc++.h>
using namespace std;



/*

正常搜索 :

int n = 0;
char words[25][105];
int len[25] = { 0 };
bool is_visited[25];
int ans = 0;

void dfs(int i, int l){
    for(int k = 0; k < n; k++){
        if(i != k and is_visited[k] == 0 and words[i][len[i]-1] == words[k][0]){
            is_visited[k] = 1;
            dfs(i + 1, l + len[k]);
            is_visited[k] = 0;
        }
    }
    ans = max(ans, l);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", words[i]);
        len[i] = strlen(words[i]);
    }

    for(int i = 0 ; i < n ; i++){
        is_visited[i] = 1;
        dfs(1, len[i]);
        is_visited[i] = 0;
    }

    printf("%d\n", ans);
    return 0;
}

*/

/* 状态压缩 */

const int only[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 }; 
char w[16][100];
int f[16][65536];
int n;
int len[16];

int work(int i, int j){
    int temp;
    int j1;
    if(f[i][j]> 0){
        return f[i][j];
    }
    j1 = j - only[i];
    for(int k = 0; k < n; k++){
        if(i != k and w[i][len[i]-1] == w[k][0] and (only[k] & j)){
            temp = work(k, j1) + len[i];
            f[i][j] = max(f[i][j], temp);
        }
    }
    return f[i][j];
}

int main(){
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", w[i]);
        len[i] = strlen(w[i]);
    }
    
    for(int i = 0; i < n; i++){
        f[i][only[i]] = len[i];
    }

    int ans = 0, temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < (1 << n); j++){
            if(only[i] & j){
                temp = work(i, j);
                ans = max(ans, temp);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

/*

[题目描述]
Io 和 Ao 在玩一个单词游戏
他们轮流说出一个仅包含元音字母的单词，并且后一个单词的第一个字母必须与钱一个单词的最后一个字母一致
游戏可以从任何一个单词开始
任何单词禁止说两遍，游戏中只能使用给定词典中含的单词
游戏的复杂度定义为游戏中所使用的单词长度的总和
编写程序求出使用一本给定词典来玩这个游戏所能达到的最大复杂度

[输入格式]
输入文件的第一行，表示个整数 N (1 <= N <= 16) 表示一个词典的单词数。
接下来 N 行每一行包含一个单词每一个单词是由字母 A、E、I、O、U 组成的一个字符串，每个单词的长度小于等于 100, 所有单词是不一样的

5
IOO
IUUO
AI
OIOOI
AOOI

16

*/