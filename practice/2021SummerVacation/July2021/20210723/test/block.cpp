#include<bits/stdc++.h>
using namespace std;

#define INFI 65535

int h, w;
int a[105][105] = { 0 };

int main(){
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	scanf("%d%d", &h, &w);
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	int mmin = INFI;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			mmin = min(mmin, a[i][j]);
		}
	}
	
	//printf("%d", mmin);
	
	int ans = 0;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			ans += (a[i][j] - mmin);
		}
	}
	
	printf("%d\n", ans);
	/*
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}
