#include<bits/stdc++.h>
using namespace std;

int patition(int data[], int low, int high){
	int pivot = data[low];
	int i = low;
	int j = high;
	while(i < j){
		do{
			i++;
		}while(data[i] < pivot);

		do{
			j--;
		}while(data[j] > pivot);

		if(i < j){
			swap(data[i],data[j]);
		}
	}
	swap(data[low],data[j]);
	return j;
}
  
 void quicksort(int data[], int low, int high){
	 if(low < high){
		 int j = patition(data, low, high);
		 quicksort(data, low, j);
		 quicksort(data, j + 1, high);
	 }
 }
 
int main() 
{
	//int data[] = { 12, 4, 34, 6, 8, 65, 3, 2, 988, 45 };
	int data[] = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
	int len = sizeof(data)/sizeof(int); 
	quicksort(data, 0, len);
	cout << "The sorted list is: ";
	for(int i = 0; i < len; i++){
		cout << data[i] << "  " ;
	}
	cout << endl;
	return 0;
}
