#include <bits/stdc++.h>
#include "giraffe.h"
using namespace std;

//TODO

/*
void print(){}
template<typename T, typename ...Types>
void print(const T arg, const Types& ...args){
	cout << arg;
	print(args...);
}

void input(){}
template<typename T, typename ...Types>
void input(T arg, Types& ...args){
	cin >> arg;
	input(args...);
}
*/

int ee;

int main(){
    giraffe<int> a;
    cin >> ee;
    for(int i = 0; i < ee; i++){
    	a[i] = i;
    	cout << a[i] << " ";
	}
    return 0;
	}
