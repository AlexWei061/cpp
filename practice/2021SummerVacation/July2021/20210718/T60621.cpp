#include<bits/stdc++.h>
using namespace std;

int l;
int r;

int countTwo(int l, int r){
	int ans = 0;
	for(int i = l; i <= r; i++){
		char numS[11];
		sprintf(numS, "%d", i);
		int len = strlen(numS);
		for(int j = 0; j < len; j++){
			if(numS[j] == '2'){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	scanf("%d%d", &l, &r);
	int ans = countTwo(l, r);
	printf("%d\n", ans);
	return 0;
}
