#include<bits/stdc++.h>
using namespace std;

int n = 8;
int arr[10] = { 0, 389, 207, 155, 300, 299, 170, 158, 65 };
int   d[10] = { 0 };
int len = 1;

bool comp(int a, int b){
	return a > b;
}

void LIS(){
    d[1] = arr[1];
	for(int i = 2; i <= n; i++){
		if(arr[i] <= d[len]){
			d[++len] = arr[i];
		}
		else{
			//int p = upper_bound(d+1, d+n+1, a[i], comp);
			int p = upper_bound(d+1, d+n+1, arr[i], greater<int>()) - d;
			d[p] = arr[i];
		}
	}
}

int main(){
	LIS();
	printf("%d\n", len);
    return 0;
}