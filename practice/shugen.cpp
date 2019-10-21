#include <bits/stdc++.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int shugen = 123;

int tot(int num){
	int sum_digits = 0;
	while(num >= 1){
		int b = num%10;
		sum_digits = sum_digits + b;
		num = (num-b) / 10;
	}
	return sum_digits;
}

int main(int argc, char** argv)
{
	while(shugen>=10){
		shugen = tot(shugen);
	} 
	cout<<shugen<<endl;
	return 0;
}	

