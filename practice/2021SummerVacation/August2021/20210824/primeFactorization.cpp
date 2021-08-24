#include<bits/stdc++.h>
using namespace std;

int n = 0;

// num = p_1^{c_1} * ... * p_i^{c_i}
int p[100] = { 0 };
int c[100] = { 0 };
void devide(int num){
	memset(p, 0, sizeof(p));
	memset(c, 0, sizeof(c));
	int m = 0;
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0){
			p[++m] = i;
			c[m] = 0;
			while(num % i == 0){
				num /= i;
				c[m]++;
			}
		}
	}
	if(num > 1){
		p[++m] = num;
		c[m] = 1;
	}

	for(int i = 1; i < m; i++){
		printf("%d ^ %d * ", p[i], c[i]);
	}
	printf("%d ^ %d\n", p[m], c[m]);
}

int main(){
	scanf("%d", &n);
	devide(n);
	return 0;
}

/*

质因数分解

*/