#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };

void merge(int l, int mid, int r){
	int i = l; int j = mid + 1;
	for(int k = l; k <= r; k++){
		if(j > r or i <= mid and a[i] <= a[j]){
			b[k] = a[i++];
		}
		else{
			b[k] = a[j++];
		}
	}
	for(int k = l; k <= r; k++){
		a[k] = b[k];
	}
}

void mergeSort(int l, int r){
	int mid = (l + r) >> 1;
	if(l < r){
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	mergeSort(1, n);
	
	for(int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	puts("");
	
	return 0;
}
