#include<bits/stdc++.h>
using namespace std;

bool compare(const int &a, const int &b){
	return a > b;                                 //Ωµ–Ú≈≈¡– 
}

int n = 0;
int numlist[100001] = { 0 };

int main(){
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	
	scanf("%d", &n);
	int j = 1;
	for(int i = 1; i <= n; i++){
		int temp = 0;
		scanf("%d", &temp);
		if(temp%2 == 0){
			numlist[j] = temp;
			j++;
		}
	}
	
	sort(numlist+1, numlist+j, compare); //Ωµ–Ú 
	
	for(int i = 1; i < j; i++){
		printf("%d ", numlist[i]);
	}
	
	return 0;
}
