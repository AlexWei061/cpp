#include<bits/stdc++.h>
using namespace std;

char numS[11];
int num[11] = { 0 };

int powerOfTen(int n){
	int a = 1;
	for(int i = 1; i <= n; i++){
		a *= 10;
	}
	return a;
}

int generateNum(int numlist[], int len){
	int ans = 0; 
	for(int i = 1; i <= len ; i++){
		ans += num[i] * powerOfTen(len-i); 
	}
	return ans;
}

void reverse(char numS[]){
	int len = strlen(numS);
	//printf("%d", len);
	bool is_nagetive = (numS[0] == '-') ? true : false; 
	
	if(is_nagetive == true){
		printf("-");
		for(int i = 1; i < len; i++){
			num[len-i] = numS[i] - 48;
		}
		int ans = generateNum(num, len-1); 
		printf("%d", ans);
	}
	else{
		for(int i = 0; i < len; i++){
			num[len-i] = numS[i] - 48;
		}
		int ans = generateNum(num, len); 
		printf("%d", ans);	
	} 
}

int main(){
	gets(numS);
	reverse(numS);
	return 0;
}
