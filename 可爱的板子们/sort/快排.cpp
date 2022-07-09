#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int n= 0;
int a[MAXN] = { 0 };

void quickSort(int l, int r){
	int mid = (l + r) >> 1;
	int pivot = a[mid];
	int i = l; int j = r;
	do{
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j){
			swap(a[i], a[j]);
			i++; j--;
		}	
	}while(i <= j);
	if(l < j) quickSort(l, j);
	if(i < r) quickSort(i, r);
}

void qsort(int l, int r){
	int pivot = a[(l + r) >> 1];
	int i = l; int j = r;
	do{
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j){
			swap(a[i], a[j]);
			i++; j--;
		}
	}while(i <= j);
	if(l < j) qsort(l, j);
	if(i < r) qsort(i, r);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	qsort(1, n);
	for(int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}
