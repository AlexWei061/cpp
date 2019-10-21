#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void quicksort(int data[], int left,int right)
{
	if (left >= right)
		return;
	int pivot = (left+right)/2;
	vector<int> less;
	vector<int> greater;
	int tmp;
	for (int i = left; i < right; i++)
	{
		if (i == pivot)
			tmp = data[pivot];
		else if (data[i] < data[pivot])
			less.push_back(data[i]);
		else
			greater.push_back(data[i]);
	}
	for (int i = left; i < right; i++)
	{
		if (i < left + less.size())
			data[i] = less[less.size() - i - 1 + left];
		else if (i == left + less.size())
			data[i] = tmp, pivot = i;
		else
			data[i] = greater[greater.size() - i+ less.size() + left];
	}
	quicksort(data,left, pivot);
	quicksort(data, pivot+1,right);
 
	
}
 
 
int main() 
{
	int data[] = { 12, 4, 34, 6, 8, 65, 3, 2, 988, 45 };
	int len = sizeof(data)/sizeof(int); 
	quicksort(data, 0, len);
	cout << "ÅÅÐòºó£º";
	for(int i = 0; i < len; i++){
		
		cout << data[i] << "  " ;
	
	}
	return 0;
}
