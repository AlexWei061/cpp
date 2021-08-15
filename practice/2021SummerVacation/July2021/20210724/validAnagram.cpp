#include<bits/stdc++.h>
using namespace std;

bool isAnagram(char *s, char *t){
    int statS[26] = { 0 };
    int statT[26] = { 0 };
    int lenS = strlen(s);
    int lenT = strlen(t);
    for(int i = 0; i < lenS; i++){
            int index = s[i] - 'a';
            statS[index]++;
    }
    for(int i = 0; i < lenT; i++){
            int index = t[i] - 'a';
            statT[index]++;
    }
    for(int i = 0; i < 26; i++){
        if(statS[i] != statT[i]){
            return false;
        }
    }
    return true;
}

int main(){
    char *s = "hello";
    char *t = "elolh";
    printf("%d", isAnagram(s, t));
    return 0;
}

/*
anagram : 相同字母异序词
*/