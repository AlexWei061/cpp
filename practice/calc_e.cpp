#include <bits/stdc++.h>
using namespace std;

long double calc_e(int n){
	long double e = 1;
	unsigned long long tmp = 1;
	for(int i = 1;i<=n;i++){
		tmp *= i;
		e += double(1.0)/tmp; 
	}
	return e;
}

int n;

int main(){
	cin>>n;
	cout<<fixed<<setprecision(30)<<calc_e(n)<<endl;
	//printf("%f.1",calc_e(n)); 
}


