#include<bits/stdc++.h>
using namespace std;

int n = 0;

void print(int n){
    int temp = 1;
    int m = n * n;
    for(int i = 1; i <= m; i++){
        if(i < 10){
            printf("%d%d", 0, i);
        }
        else{
            printf("%d", i);
        }
        if(temp == n){
            puts("");
            temp = 0;
        }
        ++temp;
    }

    puts("");

    int index = 1;
    int a = 1;
    temp = 2 * n - 2;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= temp; j++){
            printf(" ");
        }
        temp -= 2;

        for(int j = 1; j <= a; j++){
            if(index < 10){
                printf("%d%d", 0, index);
            }
            else{
                printf("%d", index);
            }
            index++;
        }
        a++;

        puts("");
    }

}

int main(){
    scanf("%d", &n);
    print(n);
    return 0;
}

/*

4

01020304
05060708
09101112
13141516

      01
    0203
  040506
07080910

*/