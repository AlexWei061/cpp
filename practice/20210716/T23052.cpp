#include<bits/stdc++.h>
using namespace std;

int k = 0;

double calcSn(int n){
	double Sn = 0;
	for(int i = 1; i <= n; i++){
		Sn += 1.0/i;
	}
	return Sn;
}

int main(){
	scanf("%d", &k);
	/*
	for(int i = 1; true; i++){
		double Sn = calcSn(i);
		if(Sn > k){
			printf("%d\n", i);
			break;
		}
	}
	用上面那段代码打出来的表 
	1 2 3  4  5  6   7   8    9    10    11    12    13     14      15
	2 4 11 31 83 227 616 1674 4550 12367 33617 91380 248397 675421  1835421	
	*/
	int anslist[16] = { 0, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675421, 1835421 }; 
	//printf("%f1", calcSn(k));
	printf("%d", anslist[k]);
	return 0;
}
