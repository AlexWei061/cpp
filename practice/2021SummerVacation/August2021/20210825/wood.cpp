#include<bits/stdc++.h>
using namespace std;

#define INFI 10010

int n = 0;
int k = 0;

int len[INFI] = { 0 };

bool can_devide(int t){                       // 判断每段长度为 t 时能否分割
	int num = 0;                              // 记录分割的段数
	for(int i = 1; i <= n; i++){
		num += len[i] / t;
		if(num >= k){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &len[i]);
	}

	int L = 0; int R = INFI;
	while(L < R){
		int mid = (L + R + 1) / 2;
		if(can_devide(mid)){
			L = mid;
		}
		else{
			R = mid - 1;
		}
	}

	printf("%d\n", L);
	
	return 0;
}


/*

把 n 根木头切成 k 段(可以有剩余) 问每小段最大的长度

3 7
232
124
456

114

*/