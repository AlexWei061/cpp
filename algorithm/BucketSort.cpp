#include<iostream>
using namespace std;

void BucketSort(int n, int num_list[]) {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d",&tmp);
		num_list[tmp]++;
	}
	for (int j = 0; j <= 100; j++) {
		for (int k = 0; k < num_list[j]; k++) {
			printf("%d%c",j,' ');
		}
	}
}

int n;
int num_list[1000001];

int main() {
	BucketSort(n, num_list);
	return 0;
}