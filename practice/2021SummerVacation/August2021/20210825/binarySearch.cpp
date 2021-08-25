#include<bits/stdc++.h>
using namespace std;

int n = 0;
int arr[10010] = { 0 };

int x = 0;

bool binarySearch(int num, int n, int arr[]){
	int l = 1; int r = n;
	while(l <= r){
        int mid = (l + r) >> 1;
        printf("l = %d r = %d mid = %d\n", l, r, mid);
		if(num > arr[mid]){
			l = mid + 1;
		}
		else if(num < arr[mid]){
			r = mid - 1;
		}
		else{
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);

	printf("%d\n", binarySearch(x, n, arr));

	return 0;
}

/*

二分查找一数是否在一个升序的数组中

*/