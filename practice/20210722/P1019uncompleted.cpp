#include<bits/stdc++.h>
using namespace std;

int n = 0;
string word[50];
string head;
int is_used[50];

bool isPrefix(string prefix, string word){                  //return if "prefix"'s prefix of "word"
    bool is_prefix = false;
    if(word.find(prefix) == 0 and word.size() > prefix.size()){
        is_prefix = true;
    }
    return is_prefix;
}

int ans = 0;
void dfs(string prefix, int len){
    ans = max(ans, len);
    for(int i = 1; i <= n; i++){                             //枚举所有字符串
        if(is_used[i] < 2){
            if(isPrefix(prefix, word[i])){
                is_used[i]++;
                int Len = word[i].size();
                for(int j = 1; j < Len; j++){                //不包含全部
                    string nprefix = word[i].substr(Len-j, i);
                    dfs(nprefix, len-prefix.size()+Len);
                }
                is_used[i]--;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        cin >> word[i];
    }
    cin >> head;

    /*
    for(int i = 1; i <= n; i++){
        cout << word[i] << endl;
    }
    */
    
    dfs(head, 1);
    printf("%d\n", ans);

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "hello";
    string b = "he";
    cout << a.find(b);
    return 0;
}
*/

/*
5
at
touch
cheat
choose
tact
a


2
abababab
abababc
a


*/