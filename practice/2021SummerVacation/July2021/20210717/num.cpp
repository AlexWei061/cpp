#include<bits/stdc++.h>
using namespace std;

int n             =   0  ;
int digitlist[11] = { 0 };

void separate(int num, int digitlist[]){
	int i = 1;
	int temp = 1;
	while(num/temp != 0){
		digitlist[i] = (num / temp) % 10;
		i++;
		temp *= 10;
	}
}

int main(){
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	scanf("%d", &n);
	separate(n, digitlist);
	/*
	for(int i = 1; i <= 10; i++){
		printf("%d", digitlist[i]);
	}
	*/
	int sum = 0;
	for(int i = 1; i <= 10; i++){
		sum += digitlist[i];
	}
	printf("%d", sum);
	return 0;
}
