#include<bits/stdc++.h>
using namespace std;

/*
char num[100];

string reverse(string num){
    bool is_n = false;
    if(num[0] == '-'){
        is_n = true;
        num.erase(0, 1);
    }
    int len = (int)num.length();
    
    for(int i = 0; i <= (len-1)/2; i++){
        swap(num[i], num[len-i-1]);
    }

    int i = 0;
    while(num[i] == '0'){
        num.erase(0, 1);
    }

    if(is_n){
        num.insert(0, "-");
    }
    return num;
}

string toString(int num){
    string ans;
    char a[100];
    sprintf(a, "%d", num);
   	ans = a;
    return ans;
}

void highLevelReverse(char num[]){
    unsigned long long a = 0, b = 0;
    char c;
    sscanf(num, "%llu%c%llu", &a, &c, &b);
    //string stra = reverse(to_string(a));
    //string strb = reverse(to_string(b));
    string stra = reverse(toString(a));
    string strb = reverse(toString(b));
    cout << stra << c << strb << endl;
}

int main(){
    scanf("%s", num);
    highLevelReverse(num);
    return 0;
}

*/

int main(){
    string s;
    char p = 0; 
    int cnt = 0; 
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' and s[i] <= '9'){
            cnt++;
        }
        else{
            p = s[i];
            break;
        } 
    }

    int x = cnt; 
    cnt--;

    while(s[cnt] == '0' and cnt > 0){
        cnt--;
    } 
    
    for(int i = cnt; i >= 0; i--){ 
        cout << s[i];
    }

    if(p == 0){ 
        return 0;
    } 

    else{
        if(p == '%'){
            cout << p;
            return 0;
        } 
        else{
            cout << p;
        }
    }

    int m = s.size() - 1;
    while(s[x+1] == '0' and x < m - 1){
        x++;
    } 
    while(s[m]=='0'&&m>x+1){
        m--;
    }
    for(int i=m;i>x;i--){
        cout<<s[i];
    }
    
    return 0; 
}

/*

5087462
2647805

600.084
6.48

700/27
7/72

8670%
768%

*/