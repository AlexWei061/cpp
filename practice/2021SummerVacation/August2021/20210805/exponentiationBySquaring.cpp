#include<bits/stdc++.h>
using namespace std;

/*

        a^(n-1) * a          if n is odd
a^n = { a^(n/2) * a^(n/2)    if n is even but not 0
        1                    if n is 0

*/

int quickPower(int a, int n){
    if(n == 0){
        return 1;
    }
    else if(n % 2 == 0){
        int temp = quickPower(a, n/2);
        return temp * temp;
    }
    else{
        return quickPower(a, n-1) * a;
    }
}

int main(){
    printf("%d\n", quickPower(2, 3));
    return 0;
}