#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int n = 0;
int ans = 0;
int a = 0; int b = 0; int c = 0;
map<double, int> s;

int main(){
	scanf("%d", &n);
	double k = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(b == 0) k = 1e9 + 1;
		else k = - (double)a / b;
		s[k]++;
		ans = max(ans, s[k]);
	}
	printf("%d\n", n - ans);
	return 0;
}