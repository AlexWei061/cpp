#include<bits/stdc++.h>
using namespace std;
#define INFI 1 << 30

int n = 0;
double p = 0;

/*
E = (\sum_{x=0}^{n-1}(p * \max_{y=0}^{n-1}{x ^ y} + (1-p)(\sum_{y=0}^{n-1} x ^ y) / n)) / n
*/

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lf", &n, &p);
	return 0;
}
