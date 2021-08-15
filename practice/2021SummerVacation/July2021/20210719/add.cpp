#include<bits/stdc++.h>
using namespace std;

int N = 0;

int a[1000] = { 0 };
int b[1000] = { 0 };

void countJw(string aChar, string bChar){
	int jw = 0;
	int c[1000] = { 0 };
	/*
	char aChar[1000];
	char bChar[1000];
	cin >> aChar >> bChar;
	*/
	int aLen = aChar.size();
	//printf("a's length = %d\n", aLen);
	int bLen = bChar.size();
	//printf("b's length = %d\n\n", bLen);
	for(int i = 0; i < aLen; i++){
		a[aLen-i] = aChar[i] - 48;
	}
	/*
	for(int i = 1; i <= aLen; i++){
		printf("i = %d ", i);
		printf("a[i] = %d\n", a[i]);
	}
	*/
	//printf("\n");
	for(int i = 0; i < bLen; i++){
		b[bLen-i] = bChar[i] - 48;
	}
	/*
	for(int i = 1; i <= bLen; i++){
		printf("i = %d ", i);
		printf("b[i] = %d\n", b[i]);
	}
	*/
	//printf("\n");
	int cLen = 1;
	while(cLen <= aLen or cLen <= bLen){
		int i = cLen;
		//printf("i = %d ", i);
		c[i] += a[i] + b[i];
		//printf("c[i]'first value = %d\n", c[i]);
		if(c[i] >= 10){
			jw++;
		}
		int temp = c[i] / 10;
		//printf("temp = %d ", temp);
		c[i] %= 10;
		//printf("c[i]'s final value = %d\n\n", c[i]);
		c[++cLen] = temp;
	}
	while(c[cLen] == 0){
		cLen--;
	}
	/*
	for(int i = cLen; i > 0; i--){
		printf("%d", c[i]);
	}
	*/
	printf("%d\n", jw);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
}

int main(){
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	string aChar;
	string bChar;
	while(cin >> aChar >> bChar and aChar != "0" and bChar != "0"){
		countJw(aChar, bChar);
	}
	return 0;
}
