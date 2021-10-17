#include<bits/stdc++.h>
using namespace std;
#define MAXN 200200
#define int long long
#define in read()

int read(){
    int x = 0; char c = getchar();
    while(c < '0' or c > '9') c = getchar();
    while('0' <= c and c <='9'){
        x = x * 10 + c - '0'; c = getchar();
    }
    return x;
}

int n = 0;
int a[MAXN] = { 0 };

double f[MAXN][10] = { 0 };
int v[MAXN][10] = { 0 };
int v1[MAXN] = { 0 };
void dp(){
	f[0][0] = (double)0;                    // 第一天黄金 1g 白银 0g
	f[0][1] = (double)1;
	for(int i = 1; i <= n; i++){
		//f[i][0] = max(f[i - 1][0], (f[i - 1][1] * (double)a[i]));
		//f[i][1] = max(f[i - 1][1], (f[i - 1][0] / (double)a[i]));
		
		if(f[i-1][0] < f[i-1][1] * (double)a[i]){
			f[i][0] = f[i-1][1] * (double)a[i];
			v[i][0] = 1;
		}
        else
            f[i][0] = f[i-1][0];

		if(f[i-1][1] < f[i-1][0] / (double)a[i]){
			f[i][1] = f[i-1][0] / (double)a[i];
			v[i][1] = 1;
		}
        else
            f[i][1] = f[i-1][1];
	}
}

signed main(){
	n = in;
	for(int i = 1; i <= n; i++){
		a[i] = in;
	}
    dp();
    
    
	for(int i = 1; i <= n; i++){
        printf("%lf ", f[i][0]);
    }
    puts("");
    for(int i = 1; i <= n; i++){
        printf("%lf ", f[i][1]);
    }
    puts("");
    
    
    for(int i = 1; i <= n; i++){
        printf("%lld ", v[i][1]);
    }
    puts("");
    for(int i = 1; i <= n; i++){
        printf("%lld ", v[i][0]);
    }
    puts("");
    

    bool is = true;
    for(int i = n; i >= 1; i--){
        //printf("i = %d is = %d\n", i, is);
        v1[i] = v[i][is];
        if(v[i][is]) is ^= 1;
    }
    for(int i = 1; i <= n; i++){
        printf("%lld ", v1[i]);
    }
    puts("");
    
	return 0;
}