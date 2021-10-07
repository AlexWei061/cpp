#include<bits/stdc++.h>
using namespace std;

char str[101];

bool isH(char str[], int L, int R){
	//printf("\nL = %d R = %d\n", L, R);
	L--; R--;
	//printf("L = %d R = %d\n", L, R);
	while(L < R){
		if(str[L] != str[R]){
			return false;
		}
		else{
			L++;
			R--;
		}
	}
	return true;
}

int main(){
	freopen("pstring.in", "r", stdin);
	freopen("pstring.out", "w", stdout);

	scanf("%s", &str);
	int n = strlen(str);
	int a = (n - 1) >> 1;
	int b = (n + 3) >> 1;

	//printf("n = %d\n", n);
	//printf("a = %d b = %d\n", a, b);

	//printf("1-n : %d\n 1-a : %d\n b-n : %d\n", isH(str, 1, n), isH(str, 1, a), isH(str, b, n));
	if(isH(str, 1, a) and isH(str, b, n) and isH(str, 1, n)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}