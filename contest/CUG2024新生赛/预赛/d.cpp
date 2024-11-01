#include<bits/stdc++.h>
using namespace std;
#define int long long 

int a = 0, num = 0;
int n = 0, row = 0, col = 0;

signed main(){
	cin >> a >> num;
	int l = 1, r = 1000001;
	int mid = l + r >> 1;
	while(l < r){
//		printf("l = %d r = %d\n", l, r);
		mid = l + r >> 1;
//		printf("mid = %d\n", mid);
		if(mid * mid >= a) r = mid;
		else l = mid + 1;
	}
//	printf("l = %d r = %d\n", l, r);
	row = ceil(double(num) / double(l)); col = num % l;
	cout << row << ' ' << col << '\n'; 
	return 0;
} 
