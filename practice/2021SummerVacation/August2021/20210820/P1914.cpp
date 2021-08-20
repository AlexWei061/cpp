#include<bits/stdc++.h>
using namespace std;

int n = 0;
char str[55];

int main(){
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int temp = str[i];
        //printf("%d\n", temp);
        temp += n;
        //printf("%d\n", temp);
        while(temp > 'z'){
            temp = 'a' + (temp - 'z') - 1;
        }
        //printf("%d\n", temp);
        str[i] = (char)temp;
        //printf("%c\n", str[i]);
    }
    printf("%s\n", str);
    return 0;
}

/*

蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位形成的。
z 的下一个字母是 a，如此循环。他现在找到了移动前的原文字符串及 n，请你求出密码。

1
qwe

rxf

*/