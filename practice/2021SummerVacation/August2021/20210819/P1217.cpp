#include<bits/stdc++.h>
using namespace std;

int a = 0;
int b = 0;

bool isHuiwen(int x){
    int temp = x, ans = 0;
    while (temp != 0) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if (ans == x){
        return true;
    }
    else{
        return false;	

    }
}

bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
	        return false;
	    }
    }
    return true;
}

bool book[100000001] = { 0 };
void prime(int b) {
    //初始化，默认全部都是质数
    memset(book, true, sizeof(book));
    book[1]=false;//1不是质数
    int n=sqrt(b);
    for (int i=2;i<=n;i++) {
        if (book[i]) {
            //质数的倍数绝对不是质数，把所有质数的倍数全部设为false
            for (int j=2;j<=b/i;j++)
                book[i*j]=false;  // i*j<=b 
        }
    }
}

int main(){
    scanf("%d%d", &a, &b);
    if(b > 10000000){
        b = 9999999;
    }
    
    prime(b);
    if(a % 2 == 0){
        a++;
    }
    for(int i = a; i <= b; i += 2){
        if(isHuiwen(i) and book[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}

/*
 
找出 [a, b] 中的回文质数

5 500

5
7
11
101
131
151
181
191
313
353
373
383

*/
