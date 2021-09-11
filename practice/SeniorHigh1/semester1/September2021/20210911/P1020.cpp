#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n = 0;
int arr[MAXN] = { 0 };
int  d1[MAXN] = { 0 };
int  d2[MAXN] = { 0 };
int len1 = 1, len2 = 1;

bool comp(int a, int b){
	return a > b;
}

// 不上升
void LIS1(){
	d1[1] = arr[1];
	for(int i = 2; i <= n; i++){
		if(arr[i] <= d1[len1]){
			d1[++len1] = arr[i];
		}
		else{
			int p = upper_bound(d1 + 1, d1 + len1 + 1, arr[i], comp) - d1;
			d1[p] = arr[i];
		}
	}
}

// 上升
void LIS2(){
	d2[1] = arr[1];
	for(int i = 2; i <= n; i++){
		if(arr[i] > d2[len2]){
			d2[++len2] = arr[i];
		}
		else{
			int p = lower_bound(d2 + 1, d2 + len2 + 1, arr[i]) - d2;
			d2[p] = arr[i];
		}
	}
}

int main(){
	freopen("a.in", "r", stdin);
	while(cin >> arr[++n]);
	n--;

	LIS1();
	LIS2();
	
	printf("%d\n%d\n", len1, len2);

	return 0;
}