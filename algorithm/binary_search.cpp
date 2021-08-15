#include <bits/stdc++.h>
using namespace std;

inline int binary_search(int left, int right, int num_list[], int num) {
	int len = sizeof(num_list);
	sort(num_list,num_list+len);
	int mid = (left + right) / 2;
	if (num_list[mid] == num) {
		return mid;
	}
	else if (num_list[mid] < num) {
		left = mid;
	}
	else if (num_list[mid] > num) {
		right = mid;
	}
	binary_search(left,right,num_list,num);
}

int num_list[8] = { 1,5,2,6,3,47,34,4 };
int num = 2;

int main() {
	int ans = binary_search(0,7,num_list,num);
	cout << "Found it,it is the " << ans+1 << "th num";
	return 0;
}
