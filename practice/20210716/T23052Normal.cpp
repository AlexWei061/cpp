#include<bits/stdc++.h>
using namespace std;

int k = 0;

int main(){
	scanf("%d", &k);
	double Sn = 0;
	int n = 1;
	while(Sn <= k){
		Sn += 1.0 / n;
		n++;
	}
	printf("%d", n-1);
	return 0;
}
