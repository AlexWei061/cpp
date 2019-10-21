#include<iostream>
using namespace std; 

void Merge(int num_list[], int l, int q, int r) {
	int n = (r - l) + 1;
	int* tmp = new int[n];
	int i = 0;
	int left = l;
	int right = q + 1;
	while (left <= q && right <= r)
		tmp[i++] = num_list[left] <= num_list[right] ? num_list[left++] : num_list[right++];
	while (left <= q) {
		tmp[i++] = num_list[left++];
	}
	while (right <= r) {
		tmp[i++] = num_list[right++];
	}
	for (int j = 0; j < n; ++j) {
		num_list[l + j] = tmp[j];
	}
	delete[] tmp;
}

void MergeSort(int num_list[], int l, int r) {
	if (l == r)
		return;  
	int q = (l + r) / 2;
	MergeSort(num_list, l, q);
	MergeSort(num_list, q + 1, r);
	Merge(num_list, l, q, r);

}

int main() {
	int num_list[8] = { 3,1,2,4,5,8,7,6 };
	int len = (sizeof(num_list) / sizeof(int));
	int l = 0;
	int r = len - 1;
	MergeSort(num_list, l, r);
	for (int i = 0; i < 8; ++i)
		printf("%d%c",num_list[i],' '); 
	return 0; 
}