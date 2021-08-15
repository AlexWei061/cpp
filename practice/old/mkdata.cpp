#include<bits/stdc++.h>
using namespace std;

void print() {}
	template<typename T, typename ...Types>
	inline void print(const T arg, const Types& ...args) {
		cout << arg << " ";
		print(args...);
	}

int main(){
	int n = 100;
	print(n,"\n");
	for(int t, i = 0; i < n; i++){
		t = rand();
		print(t);
	}
	return 0;
}
