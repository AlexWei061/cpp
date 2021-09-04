#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n = 0;
int arr[MAXN] = { 0 };

void quickSort(int L, int R){
	int mid = (L + R) >> 1;
    int pivot = arr[mid]; 
	int i = L; int j = R;
    do{
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }while(i <= j);
    if(L < j){
        quickSort(L, j);
    }
    if(i < R){
        quickSort(i, R);
    }

}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

    quickSort(1, n);

    for(int i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}