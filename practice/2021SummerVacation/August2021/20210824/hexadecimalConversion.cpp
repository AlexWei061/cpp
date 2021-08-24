#include<bits/stdc++.h>
using namespace std;

int n = 0;
int m = 0;

int arr[100] = { 0 };
void conversion(int n, int m){
	if(m == 16){
		printf("%X\n", n);
	}
	else{
		int i = 0;
        //printf("n = %d m = %d\n", n, m);
		while(n != 0){
			arr[++i] = n % m;
            //printf("    arr[%d] = %d\n", i, arr[i]);
			n /= m;
            //printf("n = %d m = %d\n", n, m);
		}

        //printf("i = %d\n", i);

		for(int j = i; j >= 1; j--){
            //printf("    j = %d\n", j);
			if(arr[j] < 10){
				printf("%d", arr[j]);
			}
			else{
				printf("%c", arr[j] - 10 + 'A');
			}
		}
		puts("");
	}
}

int main(){
	scanf("%d%d", &n, &m);
	conversion(n, m);
    
    return 0;
}
/*

将 10 进制数 n 转化为 m 进制数

*/