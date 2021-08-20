#include<bits/stdc++.h>
using namespace std;

char str[100010];

int main(){
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0 ; i< len; i++){
        if((int)str[i] >= (int)'a' and (int)str[i] <= (int)'z'){
            str[i] -= (int)('a' - 'A');
        }
    }
    printf("%s\n", str);
    return 0;
}

/*

小写转大写

*/