#include<bits/stdc++.h>
using namespace std;

string str;
//              a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
int arr[30] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };

int main(){
    int ans = 0;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            ans++;
        }
        else if(str[i] >= 'a' and str[i] <= 'z'){
            ans += arr[str[i]-'a'];
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*

手机九宫格键盘，要按出英文字母就必须要按数字键多下。例如要按出 x 就得按 9 两下，第一下会出 w，而第二下会把 w 变成 x。0 键按一下会出一个空格。

[输入格式]
一行句子，只包含英文小写字母和空格，且不超过 200 个字符。

[输出格式]
一行一个整数，表示按键盘的总次数。

i have a dream

23

*/