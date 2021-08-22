#include<bits/stdc++.h>
using namespace std;

string word;
string text;

int main(){
	freopen("a.in", "r", stdin);
    getline(cin, word);
    //scanf("\n");
    getline(cin, text);

    //cout << word << endl << text << endl;
    
    for(int i = 0; i < word.length(); i++){
        if(word[i] >= 'A' and word[i] <= 'Z'){
            word[i] += 'a' - 'A';
        }
    }

    for(int i = 0; i < text.length(); i++){
        if(text[i] >= 'A' and text[i] <= 'Z'){
            text[i] += 'a' - 'A';
        }
    }

    //cout << word << endl << text << endl;
    
    int index = text.find(word);
    if(index > text.length()){
        printf("%d\n", -1);
        return 0;
    }
    else{
        int temp = 100000000;
        int tot = 0;
        int ttot = 0;
        while((index = text.find(word)) < text.length()){
            //printf("index = %d\n", index);
            if((text[index-1] == ' ' and text[index+word.length()] == ' ') or (index == 0 and text[index+word.length()] == ' ') or (index == text.length()-word.length() and text[index-1] == ' ')){
                //printf("%d\n", 1);
                temp = min((int)(index+ttot*word.length()), temp);
                tot++;
            }
            text.erase(index, word.length());
            ttot++;
            //cout << text << endl;
        }
        if(tot == 0){
            printf("%d\n", -1);
        }
        else{
            printf("%d %d\n", tot, temp);
        }
    }
    return 0;
}

/*

u
tIXHUguyz PZYAJL  BIv NAPoemaJ aTF LOvhV m s LSa n xDn mQnO T ettIq T  AL  fG B Xme  t  fct U  tQ  d

*/