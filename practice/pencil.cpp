#include <bits/stdc++.h>
using namespace std;
int the_cheapest_way(int n,int way1n,int way1p,int way2n,int way2p,int way3n,int way3p){
	int way1a = (n+way1n-1)/way1n*way1p;
	int way2a = (n+way2n-1)/way2n*way2p;
	int way3a = (n+way3n-1)/way3n*way3p;
	int the_cheapest_price = min(way1a,min(way2a,way3a));
	return the_cheapest_price;
}


int main(){
	int n,way1n,way1p,way2n,way2p,way3n,way3p;
	cin>>n>>way1n>>way1p>>way2n>>way2p>>way3n>>way3p;
	cout<<the_cheapest_way(n,way1n,way1p,way2n,way2p,way3n,way3p)<<endl;
	return 0; 
}
