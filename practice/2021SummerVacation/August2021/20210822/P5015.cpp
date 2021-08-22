#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("a.in", "r", stdin);
    int ans = 0;
    int c;
    while((c = getchar()) != EOF){
        if(c != ' ' and c != '\n'){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}