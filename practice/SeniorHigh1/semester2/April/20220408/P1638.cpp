#include<bits/stdc++.h>
#define in read()
#define MAXN 1001000
#define MAXM 2020
using namespace std;

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0; int M = 0;
int a[MAXN] = { 0 };
int c[MAXM] = { 0 };

int main() {
	int num = 0;
    int r = -1; int l = 0; int t = 0;
	int ansL = 0; int ansR = 0;
    n = in; M = in;
    for(int i = 0; i < n; i++) a[i] = in;
    int i = 0;
    while(num != M) {
        if(c[a[i]] == 0) num++;
        c[a[i]]++; r++; i++;
    }
    while(c[a[l]] > 1) c[a[l++]]--;
    ansL = l; ansR = r;
    while(i < n) {
        c[a[i]]++; r++; i++;
        while(c[a[l]] > 1) c[a[l++]]--;
        if(ansR - ansL > r - l) ansR = r, ansL = l;
    }
    cout << ansL + 1 << ' ' << ansR + 1 << '\n';
}